import os
from datetime import datetime

import parse

################################################################################
def arg_in(a):
    return "{} {}".format(a.type, a.name)

def arg_out(a):
    if a.type in ['libfive_tree', 'libfive_float']:
        return 'Tree({})'.format(a.name)
    elif a.type == 'tvec2':
        return 'TreeVec2{{Tree({0}.x), Tree({0}.y)}}'.format(a.name)
    elif a.type == 'tvec3':
        return 'TreeVec3{{Tree({0}.x), Tree({0}.y), Tree({0}.z)}}'.format(a.name)
    elif a.type == 'int':
        return a.name
    else:
        raise RuntimeError("Unknown type %s" % a.type)

def format_module_stdlib(lib, m):
    out = '/'*80 + '''
// {}
'''.format(m)

    for f in lib[m].shapes:
        args_in = ", ".join(map(arg_in, f.args))
        args_out = ", ".join(map(arg_out, f.args))
        out += '''LIBFIVE_STDLIB {name}({args_in}) {{
    return {name}({args_out}).release();
}}
'''.format(name=f.raw_name or f.name, args_in=args_in, args_out=args_out)
    return out

################################################################################

def arg_call(a):
    if a.type == 'libfive_tree':
        return 'libfive::Tree'
    elif a.type == 'libfive_float':
        return 'TreeFloat' # same as float
    elif a.type == 'tvec2':
        return 'TreeVec2'
    elif a.type == 'tvec3':
        return 'TreeVec3'
    elif a.type in ['float', 'int']:
        return a.type
    else:
        raise RuntimeError("Unknown arg type {}".format(a.type))

def format_module_header(lib, m):
    out = '/'*80 + '''
// {}
'''.format(m)
    for f in lib[m].shapes:
        args_call = ", ".join(map(arg_call, f.args))
        out += '''libfive::Tree {name}({args_call});
'''.format(name=f.raw_name or f.name, args_call=args_call)
    return out

################################################################################

stdlib = parse.parse_stdlib()

with open('stdlib.cpp', 'w') as f:
    f.write(
'''/*
 *  C API for the libfive standard library
 *
 *  DO NOT EDIT BY HAND!
 *  This file is automatically generated from libfive/stdlib/stdlib.h
 *
 *  It was last generated on {} by user {}
 */
#include "stdlib.h"
#include "stdlib_impl.hpp"

using namespace libfive;
'''.format(datetime.now().strftime("%Y-%m-%d %H:%M:%S"), os.getlogin()))
    for m in stdlib:
        f.write(format_module_stdlib(stdlib, m))

with open('stdlib_impl.hpp', 'w') as f:
    f.write('''/*
 *  C API for the libfive standard library
 *
 *  DO NOT EDIT BY HAND!
 *  This file is automatically generated from libfive/stdlib/stdlib.h
 *
 *  It was last generated on {} by user {}
 */
#pragma once
#include "libfive/tree/tree.hpp"

// Header (hand-written in gen_c.py)
struct TreeVec2 {{
    libfive::Tree x, y;
}};
struct TreeVec3 {{
    libfive::Tree x, y, z;
}};
typedef libfive::Tree TreeFloat;

// Autogenerated content begins here

'''.format(datetime.now().strftime("%Y-%m-%d %H:%M:%S"), os.getlogin()))
    for m in stdlib:
        f.write(format_module_header(stdlib, m))

