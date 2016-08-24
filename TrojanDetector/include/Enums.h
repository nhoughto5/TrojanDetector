#ifndef ENUMS_H
#define ENHUM_H
#pragma once

enum DeviceType { DFF, F_LUT, G_LUT, lutRAM, PIP, none };

enum DeviceConfiguration { XQ_LATCH, YQ_LATCH, F_RAM, G_RAM, pip, NONE };

enum IOBType { DIFFM, DIFFS, IOB, DIFFMI, DIFFSI, IBUF };

enum ColumnType {TERM_L, IOI_L, CLB, BRAM, BRAM_IntCnct, GCLK, IOI_R, TERM_R};

enum WordType {Config_Data, FRDI_Write_Type1, LOUT, Frame_Address, NA};
#endif