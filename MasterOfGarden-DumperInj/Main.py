from pymem import Pymem
from pymem.process import inject_dll_from_path as inj_dll
from os import _exit as exitfunc
def Main():
    mogproc = Pymem("MasterOfGarden.exe")
    prochandle = mogproc.process_handle
    mogdll_utf8 = bytes("MasterOfGarden.dll", "utf-8")
    inj_dll(prochandle, mogdll_utf8)