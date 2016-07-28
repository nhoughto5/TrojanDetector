#include "Synthesizer.h"



Synthesizer::Synthesizer()
{
}


Synthesizer::~Synthesizer()
{
}

void Synthesizer::convertSchematicToHDL(std::string path) {
	printf("Executing sch2hdl\n");
	system(("sch2hdl -batch " + path + "sch2HdlBatchFile").c_str());
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
		CREATE_DEFAULT_ERROR_MODE,
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

