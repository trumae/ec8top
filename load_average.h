#ifndef _LOAD_AVERAGE

#define LINUX_SYSINFO_LOADS_SCALE 65536 //necessário para definir a escala devido ao 2¹⁶

int load_average(char *b, size_t s); //assinatura da função

#endif
