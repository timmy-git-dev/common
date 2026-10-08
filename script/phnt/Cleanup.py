import re

def snake_case(_name: str) -> str:
    return re.sub(r'(?<!^)(?=[A-Z])', '_', _name).lower()

def camelCase(_name: str) -> str:
    return _name[:1].lower() + _name[1:]

class func:
    returnType : str
    name       : str
    parameters : list[tuple[str, str]]

    def __init__(self, _returnType: str, _name: str, _parameters: list[tuple[str, str]]):
        self.returnType = _returnType
        self.name       = _name
        self.parameters = _parameters


functions : list[func] = []
with open("script/phnt/Func.hpp", "r") as _funcs:
        for _line in _funcs:
            _line = _line.strip(" ;\n")

            _line.replace(", ", ",")
            _line.replace("( ", "(")
            _line.replace(" )", ")")
            _line.replace("  ", " ")

            _start = 0
            _end = _line.find(" ", _start)
            _returnType = _line[_start:_end]

            _start = _end + 1
            _end = _line.find("(", _start)
            _funcName = _line[_start:_end]

            _start = _end + 1
            _end = _line.find(")", _start)
            _params = _line[_start:_end].split(",")
            if not _params[0]:
                _params = []

            _parameters : list[tuple[str, str]] = []
            for _param in _params:
                _param = _param.strip()
                _split = _param.rfind(" ")
                if _split != -1:
                    _parameters.append((_param[:_split], f"_{camelCase(_param[_split + 1:])}"))

            functions.append(func(_returnType, _funcName, _parameters))

def key(_function):
    return _function.name

functions.sort(key=key)

with open("inc/syscall/win/Nt.hpp", "w") as _file:
    _file.write("#pragma once\n")
    _file.write("#include \"syscall/win/Type.hpp\"\n")
    _file.write("\n")
    _file.write("namespace cmn::syscall::win\n")
    _file.write("{\n")

    for _function in functions:
        _file.write(f"    {_function.returnType} {snake_case(_function.name)}({", ".join(f"{_type} {_name}" for _type, _name in _function.parameters)});\n")

    _file.write("}")

with open("src/syscall/win/Nt.cpp", "w") as _file:
    _file.write("#include \"syscall/win/Nt.hpp\"\n")
    _file.write("#include \"syscall/win/Resolve.hpp\"\n")
    _file.write("\n")
    _file.write("namespace cmn::syscall::win\n")
    _file.write("{\n")

    for _function in functions:
        _file.write(f"    void *{camelCase(_function.name)};\n")

    _file.write("\n")
    for _function in functions:
        _file.write(f"    {_function.returnType} {snake_case(_function.name)}({", ".join(f"{_type} {_name}" for _type, _name in _function.parameters)})\n")
        _file.write( "    {\n")
        _file.write(f"        if (!{camelCase(_function.name)}) {camelCase(_function.name)} = win_::resolve_proc_address(\"{_function.name}\", {len(_function.name)});\n")
        _file.write(f"        return reinterpret_cast<{_function.returnType}(*)({", ".join(f"{_type}{'[]' if _name.endswith('[]') else ''}" for _type, _name in _function.parameters)})>({camelCase(_function.name)})({", ".join(f"{_name.removesuffix("[]")}" for _, _name in _function.parameters)});\n")
        _file.write( "    }\n")

    _file.write("}")