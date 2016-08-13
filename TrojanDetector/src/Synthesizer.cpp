#include "Synthesizer.h"

Synthesizer::Synthesizer()
{
}


Synthesizer::~Synthesizer()
{
}

void Synthesizer::singleSynthesis() {
	emit sendPercentSynthesized(0);
	synthesisSetup();
	emit sendPercentSynthesized(5);
	makeUCF(F_LUT, Coordinate(0,0));
	synthesize(true);
}

void Synthesizer::deleteAllFiles(std::string p) {
	namespace fs = boost::filesystem;
	fs::path path_to_remove(p);
	for (fs::directory_iterator end_dir_it, it(path_to_remove); it != end_dir_it; ++it) {
		fs::remove_all(it->path());
	}
}

void Synthesizer::convertSchematicToHDL(std::string path) {
	printf("Executing sch2hdl\n");
	system(("sch2hdl -batch " + path + "sch2HdlBatchFile").c_str());
}
void Synthesizer::setPath(std::string p, std::wstring wP) {
	path = p;
	wPath = wP;
}
void Synthesizer::setPath(std::string p) {
	path = p;
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	wPath = converter.from_bytes(p);
}

void Synthesizer::synthesize(bool update) {
	std::wstring ngdPath = L"C:\\Xilinx\\14.7\\ISE_DS\\ISE\\bin\\nt\\ngdbuild.exe";
	std::wstring mapPath = L"C:\\Xilinx\\14.7\\ISE_DS\\ISE\\bin\\nt\\map.exe";
	std::wstring trcePath = L"C:\\Xilinx\\14.7\\ISE_DS\\ISE\\bin\\nt\\trce.exe";
	std::wstring parPath = L"C:\\Xilinx\\14.7\\ISE_DS\\ISE\\bin\\nt\\par.exe";
	std::wstring bitgenPath = L"C:\\Xilinx\\14.7\\ISE_DS\\ISE\\bin\\nt\\bitgen.exe";
	std::wstring ngdArgs = L"-intstyle silent -quiet -dd _ngo -nt timestamp -uc item.ucf -p xa3s100e-vqg100-4 item.ngc item.ngd";
	std::wstring mapArgs = L"-intstyle silent -p xa3s100e-vqg100-4 -cm area -ir off -pr off -c 100 -o item_map.ncd item.ngd item.pcf";
	std::wstring parArgs = L"-intstyle silent -ol high -t 1 item_map.ncd item.ncd item.pcf";
	std::wstring trceArgs = L"-intstyle silent -v 3 -s 4 -n 3 -fastpaths -xml item.twx item.ncd -o item.twr item.pcf -ucf item.ucf";
	std::wstring bitgenArgs = L"-intstyle silent -f item.ut item.ncd";
	if (update) emit sendPercentSynthesized(10);
	ExecuteProcess(ngdPath, ngdArgs, 10, wPath);
	if (update) emit sendPercentSynthesized(20);
	ExecuteProcess(mapPath, mapArgs, 10, wPath);
	if (update) emit sendPercentSynthesized(40);
	ExecuteProcess(parPath, parArgs, 10, wPath);
	if (update) emit sendPercentSynthesized(60);
	ExecuteProcess(trcePath, trceArgs, 10, wPath);
	if (update) emit sendPercentSynthesized(80);
	ExecuteProcess(bitgenPath, bitgenArgs, 10, wPath);
	if (update) emit sendPercentSynthesized(100);
}

size_t Synthesizer::ExecuteProcess(std::wstring FullPathToExe, std::wstring Parameters, size_t SecondsToWait, std::wstring wPath)
{
	size_t iMyCounter = 0, iReturnVal = 0, iPos = 0;
	DWORD dwExitCode = 0;
	std::wstring sTempStr = L"";

	/* - NOTE - You should check here to see if the exe even exists */

	/* Add a space to the beginning of the Parameters */
	if (Parameters.size() != 0)
	{
		if (Parameters[0] != L' ')
		{
			Parameters.insert(0, L" ");
		}
	}

	/* The first parameter needs to be the exe itself */
	sTempStr = FullPathToExe;
	iPos = sTempStr.find_last_of(L"\\");
	sTempStr.erase(0, iPos + 1);

	Parameters = sTempStr.append(Parameters);

	/* CreateProcessW can modify Parameters thus we allocate needed memory */
	wchar_t * pwszParam = new wchar_t[Parameters.size() + 1];
	if (pwszParam == 0)
	{
		return 1;
	}
	const wchar_t* pchrTemp = Parameters.c_str();
	wcscpy_s(pwszParam, Parameters.size() + 1, pchrTemp);

	/* CreateProcess API initialization */
	STARTUPINFOW siStartupInfo;
	PROCESS_INFORMATION piProcessInfo;
	memset(&siStartupInfo, 0, sizeof(siStartupInfo));
	memset(&piProcessInfo, 0, sizeof(piProcessInfo));
	siStartupInfo.cb = sizeof(siStartupInfo);

	if (CreateProcessW(
		FullPathToExe.c_str(),
		pwszParam,
		0,
		0,
		false,
		CREATE_NO_WINDOW,
		0,
		wPath.c_str(),
		&siStartupInfo,
		&piProcessInfo) != false)
	{
		/* Watch the process. */
		dwExitCode = WaitForSingleObject(piProcessInfo.hProcess, INFINITE);
	}
	else
	{
		/* CreateProcess failed */
		iReturnVal = GetLastError();
	}

	/* Free memory */
	delete[]pwszParam;
	pwszParam = 0;

	/* Release handles */
	TerminateProcess(piProcessInfo.hProcess, 1);
	CloseHandle(piProcessInfo.hProcess);
	CloseHandle(piProcessInfo.hThread);

	return iReturnVal;
}

void Synthesizer::makeDirectories() {
	std::string outputFolder = path + "xst";
	CreateDirectoryA(outputFolder.c_str(), NULL);
	outputFolder = path + "xst/projnav.tmp";
	CreateDirectoryA(outputFolder.c_str(), NULL);
}

void Synthesizer::synthesisSetup() {
	makeDirectories();
	makeInitFiles();
	convertSchematicToHDL(path);
	std::wstring xstPath = L"C:\\Xilinx\\14.7\\ISE_DS\\ISE\\bin\\nt\\xst.exe";
	std::wstring xstArgs = L"-intstyle silent -ifn " + wPath + L"/item.xst -ofn " + wPath + L"/item.syr";
	ExecuteProcess(xstPath, xstArgs, 10, wPath);
}

void Synthesizer::makeUCF(DeviceType deviceType, Coordinate coordinate) {
	std::ofstream ucfFile;
	ucfFile.open(path + "item.ucf");
	ucfFile << "NET \"XLXN_8\" LOC = P2;\n";
	ucfFile << "NET \"XLXN_7\" LOC = P3;\n";
	if (deviceType == F_LUT) {
		ucfFile << "INST \"XLXI_11\" BEL = F;\n";
	}
	else if (deviceType == G_LUT)
	{
		ucfFile << "INST \"XLXI_11\" BEL = G;\n";
	}
	else {

	}
	ucfFile << "INST \"XLXI_11\" LOC = SLICE_X" << coordinate.X << "Y" << coordinate.Y << ";\n";
	ucfFile << "NET \"XLXN_6\" LOC = P98;\n";
	ucfFile.close();
}

void Synthesizer::makeInitFiles() {
	std::ofstream schematicFile;
	std::fstream xml;
	xml.open("Extra/schematicTemplate.xml");
	schematicFile.open(path + "item.sch");
	std::string line;
	while (xml.good())
	{
		getline(xml, line);
		schematicFile << line << "\n";
	}
	schematicFile.close();
	xml.close();



	std::ofstream sch2HdlBatchFile;
	sch2HdlBatchFile.open(path + "sch2HdlBatchFile");
	sch2HdlBatchFile << "sch2hdl,-intstyle,ise,-family,aspartan3e,-flat,-suppress,-vhdl," + path + "item.vhf,-w," + path + "item.sch";
	sch2HdlBatchFile.close();

	std::ofstream prjFile;
	prjFile.open(path + "item.prj");
	prjFile << "vhdl work \"item.vhf\"";
	prjFile.close();

	std::ofstream syrFile;
	syrFile.open(path + "item.syr");
	syrFile.close();

	std::ofstream xstFile;
	xstFile.open(path + "item.xst");
	xstFile << "set -tmpdir \"xst/projnav.tmp\"\n";
	xstFile << "set -xsthdpdir \"xst\"\n";
	xstFile << "run\n";
	xstFile << ("-ifn " + path + "item.prj\n").c_str();
	xstFile << "-ifmt mixed\n";
	xstFile << "-ofn item\n";
	xstFile << "-ofmt NGC\n";
	xstFile << "-p xa3s100e-4-vqg100\n";
	xstFile << "-top item\n";
	xstFile << "-opt_mode Speed\n";
	xstFile << "-opt_level 1\n";
	xstFile << "-iuc NO\n";
	xstFile << "-keep_hierarchy No\n";
	xstFile << "-netlist_hierarchy As_Optimized\n";
	xstFile << "-rtlview Yes\n";
	xstFile << "-glob_opt AllClockNets\n";
	xstFile << "-read_cores YES\n";
	xstFile << "-write_timing_constraints NO\n";
	xstFile << "-cross_clock_analysis NO\n";
	xstFile << "-hierarchy_separator /\n";
	xstFile << "-bus_delimiter <>\n";
	xstFile << "-case Maintain\n";
	xstFile << "-slice_utilization_ratio 100\n";
	xstFile << "-bram_utilization_ratio 100\n";
	xstFile << "-verilog2001 YES\n";
	xstFile << "-fsm_extract YES -fsm_encoding Auto\n";
	xstFile << "-safe_implementation No\n";
	xstFile << "-fsm_style LUT\n";
	xstFile << "-ram_extract Yes\n";
	xstFile << "-ram_style Auto\n";
	xstFile << "-rom_extract Yes\n";
	xstFile << "-mux_style Auto\n";
	xstFile << "-decoder_extract YES\n";
	xstFile << "-priority_extract Yes\n";
	xstFile << "-shreg_extract YES\n";
	xstFile << "-shift_extract YES\n";
	xstFile << "-xor_collapse YES\n";
	xstFile << "-rom_style Auto\n";
	xstFile << "-auto_bram_packing NO\n";
	xstFile << "-mux_extract Yes\n";
	xstFile << "-resource_sharing YES\n";
	xstFile << "-async_to_sync NO\n";
	xstFile << "-mult_style Auto\n";
	xstFile << "-iobuf YES\n";
	xstFile << "-max_fanout 100000\n";
	xstFile << "-bufg 24\n";
	xstFile << "-register_duplication YES\n";
	xstFile << "-register_balancing No\n";
	xstFile << "-slice_packing YES\n";
	xstFile << "-optimize_primitives NO\n";
	xstFile << "-use_clock_enable Yes\n";
	xstFile << "-use_sync_set Yes\n";
	xstFile << "-use_sync_reset Yes\n";
	xstFile << "-iob Auto\n";
	xstFile << "-equivalent_register_removal YES\n";
	xstFile << "-slice_utilization_ratio_maxmargin 5\n";
	xstFile.close();

	std::ofstream utFile;
	utFile.open(path + "item.ut");
	utFile << "-w\n";
	utFile << "-g DebugBitstream:Yes\n";
	utFile << "-g Binary:yes\n";
	utFile << "-g CRC:Enable\n";
	utFile << "-g ConfigRate:1\n";
	utFile << "-g ProgPin:PullUp\n";
	utFile << "-g DonePin:PullUp\n";
	utFile << "-g TckPin:PullUp\n";
	utFile << "-g TdiPin:PullUp\n";
	utFile << "-g TdoPin:PullUp\n";
	utFile << "-g TmsPin:PullUp\n";
	utFile << "-g UnusedPin:PullDown\n";
	utFile << "-g UserID:0xFFFFFFFF\n";
	utFile << "-g DCMShutdown:Disable\n";
	utFile << "-g StartUpClk:CClk\n";
	utFile << "-g DONE_cycle:4\n";
	utFile << "-g GTS_cycle:5\n";
	utFile << "-g GWE_cycle:6\n";
	utFile << "-g LCK_cycle:NoWait\n";
	utFile << "-g Security:None\n";
	utFile << "-g DonePipe:Yes\n";
	utFile << "-g DriveDone:No\n";
	utFile.close();
}

