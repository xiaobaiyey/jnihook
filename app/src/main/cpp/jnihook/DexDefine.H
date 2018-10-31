#pragma once
#ifndef DEX_SYSTEMDEFINE_H_
#define DEX_SYSTEMDEFINE_H_
#ifdef HAVE_STDINT_H
# include <stdint.h>    /* C99 */
typedef uint8_t             u1;
typedef uint16_t            u2;
typedef uint32_t            u4;
typedef uint64_t            u8;
typedef int8_t              s1;
typedef int16_t             s2;
typedef int32_t             s4;
typedef int64_t             s8;
typedef unsigned char       U1;
typedef unsigned short      U2;
typedef unsigned int        U4;
typedef unsigned long long  U8;
typedef signed char         S1;
typedef signed short        S2;
typedef signed int          S4;
typedef signed long long    S8;
typedef unsigned char       Char;
typedef unsigned short      Short;
typedef unsigned int        Int;
typedef unsigned long long  Long;
typedef unsigned char       UChar;
typedef unsigned short      UShort;
typedef unsigned int        UInt;
typedef unsigned long long  ULong;
typedef signed char         SChar;
typedef signed short        SUShort;
typedef signed int          SInt;
typedef signed long long    SLong;
#else
typedef unsigned char u1;
typedef unsigned short u2;
typedef unsigned int u4;
typedef unsigned long long u8;
typedef signed char s1;
typedef signed short s2;
typedef signed int s4;
typedef signed long long s8;
typedef unsigned char U1;
typedef unsigned short U2;
typedef unsigned int U4;
typedef unsigned long long U8;
typedef signed char S1;
typedef signed short S2;
typedef signed int S4;
typedef signed long long S8;
typedef unsigned char Char;
typedef unsigned short Short;
typedef unsigned int Int;
typedef unsigned long long Long;
typedef unsigned char UChar;
typedef unsigned char uchar;
typedef unsigned short UShort;
typedef unsigned int UInt;
typedef unsigned int uint;
typedef unsigned long long ULong;
//typedef unsigned long long  ulong;
typedef signed char SChar;
typedef signed short SUShort;
typedef signed int SInt;
typedef signed long long SLong;

enum Opcode {
    // BEGIN(libdex-opcode-enum); GENERATED AUTOMATICALLY BY opcode-gen
            OP_NOP = 0x00,
    OP_MOVE = 0x01,
    OP_MOVE_FROM16 = 0x02,
    OP_MOVE_16 = 0x03,
    OP_MOVE_WIDE = 0x04,
    OP_MOVE_WIDE_FROM16 = 0x05,
    OP_MOVE_WIDE_16 = 0x06,
    OP_MOVE_OBJECT = 0x07,
    OP_MOVE_OBJECT_FROM16 = 0x08,
    OP_MOVE_OBJECT_16 = 0x09,
    OP_MOVE_RESULT = 0x0a,
    OP_MOVE_RESULT_WIDE = 0x0b,
    OP_MOVE_RESULT_OBJECT = 0x0c,
    OP_MOVE_EXCEPTION = 0x0d,
    OP_RETURN_VOID = 0x0e,
    OP_RETURN = 0x0f,
    OP_RETURN_WIDE = 0x10,
    OP_RETURN_OBJECT = 0x11,
    OP_CONST_4 = 0x12,
    OP_CONST_16 = 0x13,
    OP_CONST = 0x14,
    OP_CONST_HIGH16 = 0x15,
    OP_CONST_WIDE_16 = 0x16,
    OP_CONST_WIDE_32 = 0x17,
    OP_CONST_WIDE = 0x18,
    OP_CONST_WIDE_HIGH16 = 0x19,
    OP_CONST_STRING = 0x1a,
    OP_CONST_STRING_JUMBO = 0x1b,
    OP_CONST_CLASS = 0x1c,
    OP_MONITOR_ENTER = 0x1d,
    OP_MONITOR_EXIT = 0x1e,
    OP_CHECK_CAST = 0x1f,
    OP_INSTANCE_OF = 0x20,
    OP_ARRAY_LENGTH = 0x21,
    OP_NEW_INSTANCE = 0x22,
    OP_NEW_ARRAY = 0x23,
    OP_FILLED_NEW_ARRAY = 0x24,
    OP_FILLED_NEW_ARRAY_RANGE = 0x25,
    OP_FILL_ARRAY_DATA = 0x26,
    OP_THROW = 0x27,
    OP_GOTO = 0x28,
    OP_GOTO_16 = 0x29,
    OP_GOTO_32 = 0x2a,
    OP_PACKED_SWITCH = 0x2b,
    OP_SPARSE_SWITCH = 0x2c,
    OP_CMPL_FLOAT = 0x2d,
    OP_CMPG_FLOAT = 0x2e,
    OP_CMPL_DOUBLE = 0x2f,
    OP_CMPG_DOUBLE = 0x30,
    OP_CMP_LONG = 0x31,
    OP_IF_EQ = 0x32,
    OP_IF_NE = 0x33,
    OP_IF_LT = 0x34,
    OP_IF_GE = 0x35,
    OP_IF_GT = 0x36,
    OP_IF_LE = 0x37,
    OP_IF_EQZ = 0x38,
    OP_IF_NEZ = 0x39,
    OP_IF_LTZ = 0x3a,
    OP_IF_GEZ = 0x3b,
    OP_IF_GTZ = 0x3c,
    OP_IF_LEZ = 0x3d,
    OP_UNUSED_3E = 0x3e,
    OP_UNUSED_3F = 0x3f,
    OP_UNUSED_40 = 0x40,
    OP_UNUSED_41 = 0x41,
    OP_UNUSED_42 = 0x42,
    OP_UNUSED_43 = 0x43,
    OP_AGET = 0x44,
    OP_AGET_WIDE = 0x45,
    OP_AGET_OBJECT = 0x46,
    OP_AGET_BOOLEAN = 0x47,
    OP_AGET_BYTE = 0x48,
    OP_AGET_CHAR = 0x49,
    OP_AGET_SHORT = 0x4a,
    OP_APUT = 0x4b,
    OP_APUT_WIDE = 0x4c,
    OP_APUT_OBJECT = 0x4d,
    OP_APUT_BOOLEAN = 0x4e,
    OP_APUT_BYTE = 0x4f,
    OP_APUT_CHAR = 0x50,
    OP_APUT_SHORT = 0x51,
    OP_IGET = 0x52,
    OP_IGET_WIDE = 0x53,
    OP_IGET_OBJECT = 0x54,
    OP_IGET_BOOLEAN = 0x55,
    OP_IGET_BYTE = 0x56,
    OP_IGET_CHAR = 0x57,
    OP_IGET_SHORT = 0x58,
    OP_IPUT = 0x59,
    OP_IPUT_WIDE = 0x5a,
    OP_IPUT_OBJECT = 0x5b,
    OP_IPUT_BOOLEAN = 0x5c,
    OP_IPUT_BYTE = 0x5d,
    OP_IPUT_CHAR = 0x5e,
    OP_IPUT_SHORT = 0x5f,
    OP_SGET = 0x60,
    OP_SGET_WIDE = 0x61,
    OP_SGET_OBJECT = 0x62,
    OP_SGET_BOOLEAN = 0x63,
    OP_SGET_BYTE = 0x64,
    OP_SGET_CHAR = 0x65,
    OP_SGET_SHORT = 0x66,
    OP_SPUT = 0x67,
    OP_SPUT_WIDE = 0x68,
    OP_SPUT_OBJECT = 0x69,
    OP_SPUT_BOOLEAN = 0x6a,
    OP_SPUT_BYTE = 0x6b,
    OP_SPUT_CHAR = 0x6c,
    OP_SPUT_SHORT = 0x6d,
    OP_INVOKE_VIRTUAL = 0x6e,
    OP_INVOKE_SUPER = 0x6f,
    OP_INVOKE_DIRECT = 0x70,
    OP_INVOKE_STATIC = 0x71,
    OP_INVOKE_INTERFACE = 0x72,
    OP_UNUSED_73 = 0x73,
    OP_INVOKE_VIRTUAL_RANGE = 0x74,
    OP_INVOKE_SUPER_RANGE = 0x75,
    OP_INVOKE_DIRECT_RANGE = 0x76,
    OP_INVOKE_STATIC_RANGE = 0x77,
    OP_INVOKE_INTERFACE_RANGE = 0x78,
    OP_UNUSED_79 = 0x79,
    OP_UNUSED_7A = 0x7a,
    OP_NEG_INT = 0x7b,
    OP_NOT_INT = 0x7c,
    OP_NEG_LONG = 0x7d,
    OP_NOT_LONG = 0x7e,
    OP_NEG_FLOAT = 0x7f,
    OP_NEG_DOUBLE = 0x80,
    OP_INT_TO_LONG = 0x81,
    OP_INT_TO_FLOAT = 0x82,
    OP_INT_TO_DOUBLE = 0x83,
    OP_LONG_TO_INT = 0x84,
    OP_LONG_TO_FLOAT = 0x85,
    OP_LONG_TO_DOUBLE = 0x86,
    OP_FLOAT_TO_INT = 0x87,
    OP_FLOAT_TO_LONG = 0x88,
    OP_FLOAT_TO_DOUBLE = 0x89,
    OP_DOUBLE_TO_INT = 0x8a,
    OP_DOUBLE_TO_LONG = 0x8b,
    OP_DOUBLE_TO_FLOAT = 0x8c,
    OP_INT_TO_BYTE = 0x8d,
    OP_INT_TO_CHAR = 0x8e,
    OP_INT_TO_SHORT = 0x8f,
    OP_ADD_INT = 0x90,
    OP_SUB_INT = 0x91,
    OP_MUL_INT = 0x92,
    OP_DIV_INT = 0x93,
    OP_REM_INT = 0x94,
    OP_AND_INT = 0x95,
    OP_OR_INT = 0x96,
    OP_XOR_INT = 0x97,
    OP_SHL_INT = 0x98,
    OP_SHR_INT = 0x99,
    OP_USHR_INT = 0x9a,
    OP_ADD_LONG = 0x9b,
    OP_SUB_LONG = 0x9c,
    OP_MUL_LONG = 0x9d,
    OP_DIV_LONG = 0x9e,
    OP_REM_LONG = 0x9f,
    OP_AND_LONG = 0xa0,
    OP_OR_LONG = 0xa1,
    OP_XOR_LONG = 0xa2,
    OP_SHL_LONG = 0xa3,
    OP_SHR_LONG = 0xa4,
    OP_USHR_LONG = 0xa5,
    OP_ADD_FLOAT = 0xa6,
    OP_SUB_FLOAT = 0xa7,
    OP_MUL_FLOAT = 0xa8,
    OP_DIV_FLOAT = 0xa9,
    OP_REM_FLOAT = 0xaa,
    OP_ADD_DOUBLE = 0xab,
    OP_SUB_DOUBLE = 0xac,
    OP_MUL_DOUBLE = 0xad,
    OP_DIV_DOUBLE = 0xae,
    OP_REM_DOUBLE = 0xaf,
    OP_ADD_INT_2ADDR = 0xb0,
    OP_SUB_INT_2ADDR = 0xb1,
    OP_MUL_INT_2ADDR = 0xb2,
    OP_DIV_INT_2ADDR = 0xb3,
    OP_REM_INT_2ADDR = 0xb4,
    OP_AND_INT_2ADDR = 0xb5,
    OP_OR_INT_2ADDR = 0xb6,
    OP_XOR_INT_2ADDR = 0xb7,
    OP_SHL_INT_2ADDR = 0xb8,
    OP_SHR_INT_2ADDR = 0xb9,
    OP_USHR_INT_2ADDR = 0xba,
    OP_ADD_LONG_2ADDR = 0xbb,
    OP_SUB_LONG_2ADDR = 0xbc,
    OP_MUL_LONG_2ADDR = 0xbd,
    OP_DIV_LONG_2ADDR = 0xbe,
    OP_REM_LONG_2ADDR = 0xbf,
    OP_AND_LONG_2ADDR = 0xc0,
    OP_OR_LONG_2ADDR = 0xc1,
    OP_XOR_LONG_2ADDR = 0xc2,
    OP_SHL_LONG_2ADDR = 0xc3,
    OP_SHR_LONG_2ADDR = 0xc4,
    OP_USHR_LONG_2ADDR = 0xc5,
    OP_ADD_FLOAT_2ADDR = 0xc6,
    OP_SUB_FLOAT_2ADDR = 0xc7,
    OP_MUL_FLOAT_2ADDR = 0xc8,
    OP_DIV_FLOAT_2ADDR = 0xc9,
    OP_REM_FLOAT_2ADDR = 0xca,
    OP_ADD_DOUBLE_2ADDR = 0xcb,
    OP_SUB_DOUBLE_2ADDR = 0xcc,
    OP_MUL_DOUBLE_2ADDR = 0xcd,
    OP_DIV_DOUBLE_2ADDR = 0xce,
    OP_REM_DOUBLE_2ADDR = 0xcf,
    OP_ADD_INT_LIT16 = 0xd0,
    OP_RSUB_INT = 0xd1,
    OP_MUL_INT_LIT16 = 0xd2,
    OP_DIV_INT_LIT16 = 0xd3,
    OP_REM_INT_LIT16 = 0xd4,
    OP_AND_INT_LIT16 = 0xd5,
    OP_OR_INT_LIT16 = 0xd6,
    OP_XOR_INT_LIT16 = 0xd7,
    OP_ADD_INT_LIT8 = 0xd8,
    OP_RSUB_INT_LIT8 = 0xd9,
    OP_MUL_INT_LIT8 = 0xda,
    OP_DIV_INT_LIT8 = 0xdb,
    OP_REM_INT_LIT8 = 0xdc,
    OP_AND_INT_LIT8 = 0xdd,
    OP_OR_INT_LIT8 = 0xde,
    OP_XOR_INT_LIT8 = 0xdf,
    OP_SHL_INT_LIT8 = 0xe0,
    OP_SHR_INT_LIT8 = 0xe1,
    OP_USHR_INT_LIT8 = 0xe2,
    OP_IGET_VOLATILE = 0xe3,
    OP_IPUT_VOLATILE = 0xe4,
    OP_SGET_VOLATILE = 0xe5,
    OP_SPUT_VOLATILE = 0xe6,
    OP_IGET_OBJECT_VOLATILE = 0xe7,
    OP_IGET_WIDE_VOLATILE = 0xe8,
    OP_IPUT_WIDE_VOLATILE = 0xe9,
    OP_SGET_WIDE_VOLATILE = 0xea,
    OP_SPUT_WIDE_VOLATILE = 0xeb,
    OP_BREAKPOINT = 0xec,
    OP_THROW_VERIFICATION_ERROR = 0xed,
    OP_EXECUTE_INLINE = 0xee,
    OP_EXECUTE_INLINE_RANGE = 0xef,
    OP_INVOKE_OBJECT_INIT_RANGE = 0xf0,
    OP_RETURN_VOID_BARRIER = 0xf1,
    OP_IGET_QUICK = 0xf2,
    OP_IGET_WIDE_QUICK = 0xf3,
    OP_IGET_OBJECT_QUICK = 0xf4,
    OP_IPUT_QUICK = 0xf5,
    OP_IPUT_WIDE_QUICK = 0xf6,
    OP_IPUT_OBJECT_QUICK = 0xf7,
    OP_INVOKE_VIRTUAL_QUICK = 0xf8,
    OP_INVOKE_VIRTUAL_QUICK_RANGE = 0xf9,
    OP_INVOKE_SUPER_QUICK = 0xfa,
    OP_INVOKE_SUPER_QUICK_RANGE = 0xfb,
    OP_IPUT_OBJECT_VOLATILE = 0xfc,
    OP_SGET_OBJECT_VOLATILE = 0xfd,
    OP_SPUT_OBJECT_VOLATILE = 0xfe,
    OP_UNUSED_FF = 0xff,
    // END(libdex-opcode-enum)
};

#endif
#ifndef _DEX_GEN_INLINES             /* only defined by DexInlines.c */
#define DEX_INLINE        extern __inline__
#else
#define DEX_INLINE
#endif

/* DEX file magic number */
#define DEX_MAGIC        "dex\n"
/* version, encoded in 4 bytes of ASCII */
#define DEX_MAGIC_VERS        "035\0"
/* same, but for optimized DEX header */
#define DEX_OPT_MAGIC    "dey\n"
#define DEX_OPT_MAGIC_VERS    "036\0"
#define DEX_DEP_MAGIC    "deps"
/*
 * 160-bit SHA-1 digest.
 */
enum {
    kSHA1DigestLen = 20,
    kSHA1DigestOutputLen = kSHA1DigestLen * 2 + 1
};
/* general constants */
enum {
    kDexEndianConstant = 0x12345678,    /* the endianness indicator */
    kDexNoIndex = 0xffffffff,           /* not a valid index value */
};
/*
 * access flags and masks; the "standard" ones are all <= 0x4000
 *
 * Note: There are related declarations in vm/oo/Object.h in the ClassFlags
 * enum.
 */
enum {
    ACC_PUBLIC = 0x00000001,       // class, field, method, ic
    ACC_PRIVATE = 0x00000002,       // field, method, ic
    ACC_PROTECTED = 0x00000004,       // field, method, ic
    ACC_STATIC = 0x00000008,       // field, method, ic
    ACC_FINAL = 0x00000010,       // class, field, method, ic
    ACC_SYNCHRONIZED = 0x00000020,       // method (only allowed on natives)
    ACC_SUPER = 0x00000020,       // class (not used in Dalvik)
    ACC_VOLATILE = 0x00000040,       // field
    ACC_BRIDGE = 0x00000040,       // method (1.5)
    ACC_TRANSIENT = 0x00000080,       // field
    ACC_VARARGS = 0x00000080,       // method (1.5)
    ACC_NATIVE = 0x00000100,       // method
    ACC_INTERFACE = 0x00000200,       // class, ic
    ACC_ABSTRACT = 0x00000400,       // class, method, ic
    ACC_STRICT = 0x00000800,       // method
    ACC_SYNTHETIC = 0x00001000,       // field, method, ic
    ACC_ANNOTATION = 0x00002000,       // class, ic (1.5)
    ACC_ENUM = 0x00004000,       // class, field, ic (1.5)
    ACC_CONSTRUCTOR = 0x00010000,       // method (Dalvik only)
    ACC_DECLARED_SYNCHRONIZED =
    0x00020000,       // method (Dalvik only)
    ACC_CLASS_MASK =
    (ACC_PUBLIC | ACC_FINAL | ACC_INTERFACE | ACC_ABSTRACT
     | ACC_SYNTHETIC | ACC_ANNOTATION | ACC_ENUM),
    ACC_INNER_CLASS_MASK =
    (ACC_CLASS_MASK | ACC_PRIVATE | ACC_PROTECTED | ACC_STATIC),
    ACC_FIELD_MASK =
    (ACC_PUBLIC | ACC_PRIVATE | ACC_PROTECTED | ACC_STATIC | ACC_FINAL
     | ACC_VOLATILE | ACC_TRANSIENT | ACC_SYNTHETIC | ACC_ENUM),
    ACC_METHOD_MASK =
    (ACC_PUBLIC | ACC_PRIVATE | ACC_PROTECTED | ACC_STATIC | ACC_FINAL
     | ACC_SYNCHRONIZED | ACC_BRIDGE | ACC_VARARGS | ACC_NATIVE
     | ACC_ABSTRACT | ACC_STRICT | ACC_SYNTHETIC | ACC_CONSTRUCTOR
     | ACC_DECLARED_SYNCHRONIZED),
};
/* annotation constants */
enum {
    kDexVisibilityBuild = 0x00,     /* annotation visibility */
    kDexVisibilityRuntime = 0x01,
    kDexVisibilitySystem = 0x02,
    kDexAnnotationByte = 0x00,
    kDexAnnotationShort = 0x02,
    kDexAnnotationChar = 0x03,
    kDexAnnotationInt = 0x04,
    kDexAnnotationLong = 0x06,
    kDexAnnotationFloat = 0x10,
    kDexAnnotationDouble = 0x11,
    kDexAnnotationString = 0x17,
    kDexAnnotationType = 0x18,
    kDexAnnotationField = 0x19,
    kDexAnnotationMethod = 0x1a,
    kDexAnnotationEnum = 0x1b,
    kDexAnnotationArray = 0x1c,
    kDexAnnotationAnnotation = 0x1d,
    kDexAnnotationNull = 0x1e,
    kDexAnnotationBoolean = 0x1f,
    kDexAnnotationValueTypeMask = 0x1f,     /* low 5 bits */
    kDexAnnotationValueArgShift = 5,
};
/* map item type codes */
enum {
    kDexTypeHeaderItem = 0x0000,
    kDexTypeStringIdItem = 0x0001,
    kDexTypeTypeIdItem = 0x0002,
    kDexTypeProtoIdItem = 0x0003,
    kDexTypeFieldIdItem = 0x0004,
    kDexTypeMethodIdItem = 0x0005,
    kDexTypeClassDefItem = 0x0006,
    kDexTypeMapList = 0x1000,
    kDexTypeTypeList = 0x1001,
    kDexTypeAnnotationSetRefList = 0x1002,
    kDexTypeAnnotationSetItem = 0x1003,
    kDexTypeClassDataItem = 0x2000,
    kDexTypeCodeItem = 0x2001,
    kDexTypeStringDataItem = 0x2002,
    kDexTypeDebugInfoItem = 0x2003,
    kDexTypeAnnotationItem = 0x2004,
    kDexTypeEncodedArrayItem = 0x2005,
    kDexTypeAnnotationsDirectoryItem = 0x2006,
};
/* auxillary data section chunk codes */
enum {
    kDexChunkClassLookup = 0x434c4b50,   /* CLKP */
    kDexChunkRegisterMaps = 0x524d4150,   /* RMAP */
    kDexChunkReducingIndexMap = 0x5249584d,   /* RIXM */
    kDexChunkExpandingIndexMap = 0x4549584d,   /* EIXM */
    kDexChunkEnd = 0x41454e44,   /* AEND */
};
/* debug info opcodes and constants */
enum {
    DBG_END_SEQUENCE = 0x00,
    DBG_ADVANCE_PC = 0x01,
    DBG_ADVANCE_LINE = 0x02,
    DBG_START_LOCAL = 0x03,
    DBG_START_LOCAL_EXTENDED = 0x04,
    DBG_END_LOCAL = 0x05,
    DBG_RESTART_LOCAL = 0x06,
    DBG_SET_PROLOGUE_END = 0x07,
    DBG_SET_EPILOGUE_BEGIN = 0x08,
    DBG_SET_FILE = 0x09,
    DBG_FIRST_SPECIAL = 0x0a,
    DBG_LINE_BASE = -4,
    DBG_LINE_RANGE = 15,
};

/*
 * Direct-mapped "header_item" struct.
 */
typedef struct DexHeader {
    u1 magic[8];           /* includes version number */
    u4 checksum;           /* adler32 checksum */
    u1 signature[kSHA1DigestLen]; /* SHA-1 hash */
    u4 fileSize;           /* length of entire file */
    u4 headerSize;         /* offset to start of next section */
    u4 endianTag;
    u4 linkSize;
    u4 linkOff;
    u4 mapOff;
    u4 stringIdsSize;
    u4 stringIdsOff;
    u4 typeIdsSize;
    u4 typeIdsOff;
    u4 protoIdsSize;
    u4 protoIdsOff;
    u4 fieldIdsSize;
    u4 fieldIdsOff;
    u4 methodIdsSize;
    u4 methodIdsOff;
    u4 classDefsSize;
    u4 classDefsOff;
    u4 dataSize;
    u4 dataOff;
} DexHeader, *LP_DexHeader;
/*
 * Direct-mapped "map_item".
 */
typedef struct DexMapItem {
    u2 type;              /* type code (see kDexType* above) */
    u2 unused;
    u4 size;              /* count of items of the indicated type */
    u4 offset;            /* file offset to the start of data */
} DexMapItem;

/*
 * Direct-mapped "map_list".
 */
typedef struct DexMapList {
    u4 size;               /* #of entries in list */
    DexMapItem list[1];     /* entries */
} DexMapList;

/*
 * Direct-mapped "string_id_item".
 */
typedef struct DexStringId {
    u4 stringDataOff;      /* file offset to string_data_item */
} DexStringId;
/*
 * Direct-mapped "type_id_item".
 */
typedef struct DexTypeId {
    u4 descriptorIdx;      /* index into stringIds list for type descriptor */
} DexTypeId;
/*
 * Direct-mapped "field_id_item".
 */
typedef struct DexFieldId {
    u2 classIdx;           /* index into typeIds list for defining class */
    u2 typeIdx;            /* index into typeIds for field type */
    u4 nameIdx;            /* index into stringIds for field name */
} DexFieldId;

/*
 * Direct-mapped "method_id_item".
 */
typedef struct DexMethodId {
    u2 classIdx;           /* index into typeIds list for defining class */
    u2 protoIdx;           /* index into protoIds for method prototype */
    u4 nameIdx;            /* index into stringIds for method name */
} DexMethodId;
/*
 * Direct-mapped "proto_id_item".
 */
typedef struct DexProtoId {
    u4 shortyIdx;          /* index into stringIds for shorty descriptor */
    u4 returnTypeIdx;      /* index into typeIds list for return type */
    u4 parametersOff;      /* file offset to type_list for parameter types */
} DexProtoId;
/**/
typedef struct DexMapId {
    u2 type;             /*Section type*/

    u2 unused;            /*unused*/
    u4 size;                /* section size*/
    u4 offset;            /* section offset */
} DexMapId;
/*
 * Direct-mapped "class_def_item".
 */
typedef struct DexClassDef {
    u4 classIdx;           /* index into typeIds for this class */
    u4 accessFlags;
    u4 superclassIdx;      /* index into typeIds for superclass */
    u4 interfacesOff;      /* file offset to DexTypeList */
    u4 sourceFileIdx;      /* index into stringIds for source file name */
    u4 annotationsOff;     /* file offset to annotations_directory_item */
    u4 classDataOff;       /* file offset to class_data_item */
    u4 staticValuesOff;    /* file offset to DexEncodedArray */
} DexClassDef;
/*
 * Direct-mapped "type_item".
 */
typedef struct DexTypeItem {
    u2 typeIdx;            /* index into typeIds */
} DexTypeItem;

/*
 * Direct-mapped "type_list".
 */
typedef struct DexTypeList {
    u4 size;               /* #of entries in list */
    DexTypeItem list[1];    /* entries */
} DexTypeList;
/*
 * Link table.  Currently undefined.
 */
typedef struct DexLink {
    u1 bleargh;
} DexLink;
/*
 * Direct-mapped "annotations_directory_item".
 */
typedef struct DexAnnotationsDirectoryItem {
    u4 classAnnotationsOff;  /* offset to DexAnnotationSetItem */
    u4 fieldsSize;           /* count of DexFieldAnnotationsItem */
    u4 methodsSize;          /* count of DexMethodAnnotationsItem */
    u4 parametersSize;       /* count of DexParameterAnnotationsItem */
    /* followed by DexFieldAnnotationsItem[fieldsSize] */
    /* followed by DexMethodAnnotationsItem[methodsSize] */
    /* followed by DexParameterAnnotationsItem[parametersSize] */
} DexAnnotationsDirectoryItem;

/*
 * Direct-mapped "field_annotations_item".
 */
typedef struct DexFieldAnnotationsItem {
    u4 fieldIdx;
    u4 annotationsOff;             /* offset to DexAnnotationSetItem */
} DexFieldAnnotationsItem;

/*
 * Direct-mapped "method_annotations_item".
 */
typedef struct DexMethodAnnotationsItem {
    u4 methodIdx;
    u4 annotationsOff;             /* offset to DexAnnotationSetItem */
} DexMethodAnnotationsItem;

/*
 * Direct-mapped "parameter_annotations_item".
 */
typedef struct DexParameterAnnotationsItem {
    u4 methodIdx;
    u4 annotationsOff;             /* offset to DexAnotationSetRefList */
} DexParameterAnnotationsItem;

/*
 * Direct-mapped "annotation_set_ref_item".
 */
typedef struct DexAnnotationSetRefItem {
    u4 annotationsOff;             /* offset to DexAnnotationSetItem */
} DexAnnotationSetRefItem;

/*
 * Direct-mapped "annotation_set_ref_list".
 */
typedef struct DexAnnotationSetRefList {
    u4 size;
    DexAnnotationSetRefItem list[1];
} DexAnnotationSetRefList;

/*
 * Direct-mapped "anotation_set_item".
 */
typedef struct DexAnnotationSetItem {
    u4 size;
    u4 entries[1];                 /* offset to DexAnnotationItem */
} DexAnnotationSetItem;

/*
 * Direct-mapped "annotation_item".
 *
 * NOTE: this structure is byte-aligned.
 */
typedef struct DexAnnotationItem {
    u1 visibility;
    u1 annotation[1];              /* data in encoded_annotation format */
} DexAnnotationItem;

/*
 * Direct-mapped "encoded_array".
 *
 * NOTE: this structure is byte-aligned.
 */
typedef struct DexEncodedArray {
    u1 array[1];                   /* data in encoded_array format */
} DexEncodedArray;

/*
 * Lookup table for classes.  It provides a mapping from class name to
 * class definition.  Used by dexFindClass().
 *
 * We calculate this at DEX optimization time and embed it in the file so we
 * don't need the same hash table in every VM.  This is slightly slower than
 * a hash table with direct pointers to the items, but because it's shared
 * there's less of a penalty for using a fairly sparse table.
 */
typedef struct DexClassLookup {
    int size;                       // total size, including "size"
    int numEntries;                 // size of table[]; always power of 2
    struct {
        u4 classDescriptorHash;    // class descriptor hash code
        int classDescriptorOffset;  // in bytes, from start of DEX
        int classDefOffset;         // in bytes, from start of DEX
    } table[1];
} DexClassLookup;

/*
 * Map constant pool indices from one form to another.  Some or all of these
 * may be NULL.
 *
 * The map values are 16-bit unsigned values.  If the values we map to
 * require a larger range, we omit the mapping for that category (which
 * requires that the lookup code recognize that the data will not be
 * there for all DEX files in all categories.)
 */
typedef struct DexIndexMap {
    const u2 *classMap;         /* map, either expanding or reducing */
    u4 classFullCount;         /* same as typeIdsSize */
    u4 classReducedCount;      /* post-reduction count */
    const u2 *methodMap;
    u4 methodFullCount;
    u4 methodReducedCount;
    const u2 *fieldMap;
    u4 fieldFullCount;
    u4 fieldReducedCount;
    const u2 *stringMap;
    u4 stringFullCount;
    u4 stringReducedCount;
} DexIndexMap;

/*
 * Header added by DEX optimization pass.  Values are always written in
 * local byte and structure padding.  The first field (magic + version)
 * is guaranteed to be present and directly readable for all expected
 * compiler configurations; the rest is version-dependent.
 *
 * Try to keep this simple and fixed-size.
 */
typedef struct DexOptHeader {
    u1 magic[8];           /* includes version number */
    u4 dexOffset;          /* file offset of DEX header */
    u4 dexLength;
    u4 depsOffset;         /* offset of optimized DEX dependency table */
    u4 depsLength;
    u4 auxOffset;          /* file offset of pre-calc auxillary data */
    u4 auxLength;
    u4 flags;              /* some info flags */
    u4 checksum;           /* adler32 checksum covering deps/aux */
    /* pad for 64-bit alignment if necessary */
} DexOptHeader;

#define DEX_FLAG_VERIFIED           (1)     /* tried to verify all classes */
#define DEX_OPT_FLAG_BIG            (1<<1)  /* swapped to big-endian */
#define DEX_OPT_FLAG_FIELDS         (1<<2)  /* field access optimized */
#define DEX_OPT_FLAG_INVOCATIONS    (1<<3)  /* method calls optimized */
#define DEX_INTERFACE_CACHE_SIZE    128     /* must be power of 2 */

/*
 * Structure representing a DEX file.
 *
 * Code should regard DexFile as opaque, using the API calls provided here
 * to access specific structures.
 */
typedef struct DexFile {
    /* directly-mapped "opt" header */
    const DexOptHeader *pOptHeader;
    /* pointers to directly-mapped structs and arrays in base DEX */
    const DexHeader *pHeader;
    const DexStringId *pStringIds;
    const DexTypeId *pTypeIds;
    const DexFieldId *pFieldIds;
    const DexMethodId *pMethodIds;
    const DexProtoId *pProtoIds;
    const DexClassDef *pClassDefs;
    const DexLink *pLinkData;
    /*
     * These are mapped out of the "auxillary" section, and may not be
     * included in the file.
     */
    const DexClassLookup *pClassLookup;
    DexIndexMap indexMap;
    const void *pRegisterMapPool;       // RegisterMapClassPool

    /* points to start of DEX file data */
    const u1 *baseAddr;

    /* track memory overhead for auxillary structures */
    int overhead;

    /* additional app-specific data structures associated with the DEX */
    //void*               auxData;
} DexFile;
//
struct DexCode {
    u2 registersSize;
    u2 insSize;
    u2 outsSize;
    u2 triesSize;
    u4 debugInfoOff;       /* file offset to debug info stream */
    u4 insnsSize;          /* size of the insns array, in u2 units */
    u2 insns[1];
    /* followed by optional u2 padding */
    /* followed by try_item[triesSize] */
    /* followed by uleb128 handlersSize */
    /* followed by catch_handler_item[handlersSize] */
};

struct try_item {
    int startIns;
    u2 sizeIns;
    u2 handleroff;
};
enum PrimitiveType {
    PRIM_NOT = 0, /* value is a reference type, not a primitive type */
    PRIM_VOID = 1,
    PRIM_BOOLEAN = 2,
    PRIM_BYTE = 3,
    PRIM_SHORT = 4,
    PRIM_CHAR = 5,
    PRIM_INT = 6,
    PRIM_LONG = 7,
    PRIM_FLOAT = 8,
    PRIM_DOUBLE = 9,
};

struct JarFile {
    u4 *Nocare[9];
    char *cacheFileName;
    struct DvmDex *pDvmDex;
};

struct RawDexFile {
    char *cacheFileName;
    struct DvmDex *pDvmDex; //DvmDex*
};

struct DexOrJar {
    char *fileName;
    bool isDex;
    bool okayToFree;
    RawDexFile *pRawDexFile;
    JarFile *pJarFile;
    u1 *pDexMemory; // malloc()ed memory, if any
};


enum InstructionFormat {
    kFmt00x = 0,    // unknown format (also used for "breakpoint" opcode)
    kFmt10x,        // op
    kFmt12x,        // op vA, vB
    kFmt11n,        // op vA, #+B
    kFmt11x,        // op vAA
    kFmt10t,        // op +AA
    kFmt20bc,       // [opt] op AA, thing@BBBB
    kFmt20t,        // op +AAAA
    kFmt22x,        // op vAA, vBBBB
    kFmt21t,        // op vAA, +BBBB
    kFmt21s,        // op vAA, #+BBBB
    kFmt21h,        // op vAA, #+BBBB00000[00000000]
    kFmt21c,        // op vAA, thing@BBBB
    kFmt23x,        // op vAA, vBB, vCC
    kFmt22b,        // op vAA, vBB, #+CC
    kFmt22t,        // op vA, vB, +CCCC
    kFmt22s,        // op vA, vB, #+CCCC
    kFmt22c,        // op vA, vB, thing@CCCC
    kFmt22cs,       // [opt] op vA, vB, field offset CCCC
    kFmt30t,        // op +AAAAAAAA
    kFmt32x,        // op vAAAA, vBBBB
    kFmt31i,        // op vAA, #+BBBBBBBB
    kFmt31t,        // op vAA, +BBBBBBBB
    kFmt31c,        // op vAA, string@BBBBBBBB
    kFmt35c,        // op {vC,vD,vE,vF,vG}, thing@BBBB
    kFmt35ms,       // [opt] invoke-virtual+super
    kFmt3rc,        // op {vCCCC .. v(CCCC+AA-1)}, thing@BBBB
    kFmt3rms,       // [opt] invoke-virtual+super/range
    kFmt51l,        // op vAA, #+BBBBBBBBBBBBBBBB
    kFmt35mi,       // [opt] inline invoke
    kFmt3rmi,       // [opt] inline invoke/range
};
static u1 gInstructionFormatTable[0x100] = {
        // BEGIN(libdex-formats); GENERATED AUTOMATICALLY BY opcode-gen
        kFmt10x, kFmt12x, kFmt22x, kFmt32x, kFmt12x, kFmt22x, kFmt32x,
        kFmt12x, kFmt22x, kFmt32x, kFmt11x, kFmt11x, kFmt11x, kFmt11x,
        kFmt10x, kFmt11x, kFmt11x, kFmt11x, kFmt11n, kFmt21s, kFmt31i,
        kFmt21h, kFmt21s, kFmt31i, kFmt51l, kFmt21h, kFmt21c, kFmt31c,
        kFmt21c, kFmt11x, kFmt11x, kFmt21c, kFmt22c, kFmt12x, kFmt21c,
        kFmt22c, kFmt35c, kFmt3rc, kFmt31t, kFmt11x, kFmt10t, kFmt20t,
        kFmt30t, kFmt31t, kFmt31t, kFmt23x, kFmt23x, kFmt23x, kFmt23x,
        kFmt23x, kFmt22t, kFmt22t, kFmt22t, kFmt22t, kFmt22t, kFmt22t,
        kFmt21t, kFmt21t, kFmt21t, kFmt21t, kFmt21t, kFmt21t, kFmt00x,
        kFmt00x, kFmt00x, kFmt00x, kFmt00x, kFmt00x, kFmt23x, kFmt23x,
        kFmt23x, kFmt23x, kFmt23x, kFmt23x, kFmt23x, kFmt23x, kFmt23x,
        kFmt23x, kFmt23x, kFmt23x, kFmt23x, kFmt23x, kFmt22c, kFmt22c,
        kFmt22c, kFmt22c, kFmt22c, kFmt22c, kFmt22c, kFmt22c, kFmt22c,
        kFmt22c, kFmt22c, kFmt22c, kFmt22c, kFmt22c, kFmt21c, kFmt21c,
        kFmt21c, kFmt21c, kFmt21c, kFmt21c, kFmt21c, kFmt21c, kFmt21c,
        kFmt21c, kFmt21c, kFmt21c, kFmt21c, kFmt21c, kFmt35c, kFmt35c,
        kFmt35c, kFmt35c, kFmt35c, kFmt00x, kFmt3rc, kFmt3rc, kFmt3rc,
        kFmt3rc, kFmt3rc, kFmt00x, kFmt00x, kFmt12x, kFmt12x, kFmt12x,
        kFmt12x, kFmt12x, kFmt12x, kFmt12x, kFmt12x, kFmt12x, kFmt12x,
        kFmt12x, kFmt12x, kFmt12x, kFmt12x, kFmt12x, kFmt12x, kFmt12x,
        kFmt12x, kFmt12x, kFmt12x, kFmt12x, kFmt23x, kFmt23x, kFmt23x,
        kFmt23x, kFmt23x, kFmt23x, kFmt23x, kFmt23x, kFmt23x, kFmt23x,
        kFmt23x, kFmt23x, kFmt23x, kFmt23x, kFmt23x, kFmt23x, kFmt23x,
        kFmt23x, kFmt23x, kFmt23x, kFmt23x, kFmt23x, kFmt23x, kFmt23x,
        kFmt23x, kFmt23x, kFmt23x, kFmt23x, kFmt23x, kFmt23x, kFmt23x,
        kFmt23x, kFmt12x, kFmt12x, kFmt12x, kFmt12x, kFmt12x, kFmt12x,
        kFmt12x, kFmt12x, kFmt12x, kFmt12x, kFmt12x, kFmt12x, kFmt12x,
        kFmt12x, kFmt12x, kFmt12x, kFmt12x, kFmt12x, kFmt12x, kFmt12x,
        kFmt12x, kFmt12x, kFmt12x, kFmt12x, kFmt12x, kFmt12x, kFmt12x,
        kFmt12x, kFmt12x, kFmt12x, kFmt12x, kFmt12x, kFmt22s, kFmt22s,
        kFmt22s, kFmt22s, kFmt22s, kFmt22s, kFmt22s, kFmt22s, kFmt22b,
        kFmt22b, kFmt22b, kFmt22b, kFmt22b, kFmt22b, kFmt22b, kFmt22b,
        kFmt22b, kFmt22b, kFmt22b, kFmt22c, kFmt22c, kFmt21c, kFmt21c,
        kFmt22c, kFmt22c, kFmt22c, kFmt21c, kFmt21c, kFmt00x, kFmt20bc,
        kFmt35mi, kFmt3rmi, kFmt35c, kFmt10x, kFmt22cs, kFmt22cs, kFmt22cs,
        kFmt22cs, kFmt22cs, kFmt22cs, kFmt35ms, kFmt3rms, kFmt35ms, kFmt3rms,
        kFmt22c, kFmt21c, kFmt21c, kFmt00x,
        // END(libdex-formats)
};

enum InstructionIndexType {
    kIndexUnknown = 0,
    kIndexNone,         // has no index
    kIndexVaries,       // "It depends." Used for throw-verification-error
    kIndexTypeRef,      // type reference index
    kIndexStringRef,    // string reference index
    kIndexMethodRef,    // method reference index
    kIndexFieldRef,     // field reference index
    kIndexInlineMethod, // inline method index (for inline linked methods)
    kIndexVtableOffset, // vtable offset (for static linked methods)
    kIndexFieldOffset   // field offset (for static linked fields)
};

/*
* Holds the contents of a decoded instruction.
*/
struct DecodedInstruction {
    u4 vA;
    u4 vB;
    u8 vB_wide;        /* for kFmt51l */
    u4 vC;
    u4 arg[5];         /* vC/D/E/F/G in invoke or filled-new-array */
    Opcode opcode;
    InstructionIndexType indexType;
};

static u1 gInstructionIndexTypeTable[0x100] = {
        // BEGIN(libdex-index-types); GENERATED AUTOMATICALLY BY opcode-gen
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexStringRef,
        kIndexStringRef, kIndexTypeRef, kIndexNone,
        kIndexNone, kIndexTypeRef, kIndexTypeRef,
        kIndexNone, kIndexTypeRef, kIndexTypeRef,
        kIndexTypeRef, kIndexTypeRef, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexUnknown,
        kIndexUnknown, kIndexUnknown, kIndexUnknown,
        kIndexUnknown, kIndexUnknown, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexFieldRef, kIndexFieldRef,
        kIndexFieldRef, kIndexFieldRef, kIndexFieldRef,
        kIndexFieldRef, kIndexFieldRef, kIndexFieldRef,
        kIndexFieldRef, kIndexFieldRef, kIndexFieldRef,
        kIndexFieldRef, kIndexFieldRef, kIndexFieldRef,
        kIndexFieldRef, kIndexFieldRef, kIndexFieldRef,
        kIndexFieldRef, kIndexFieldRef, kIndexFieldRef,
        kIndexFieldRef, kIndexFieldRef, kIndexFieldRef,
        kIndexFieldRef, kIndexFieldRef, kIndexFieldRef,
        kIndexFieldRef, kIndexFieldRef, kIndexMethodRef,
        kIndexMethodRef, kIndexMethodRef, kIndexMethodRef,
        kIndexMethodRef, kIndexUnknown, kIndexMethodRef,
        kIndexMethodRef, kIndexMethodRef, kIndexMethodRef,
        kIndexMethodRef, kIndexUnknown, kIndexUnknown,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexNone,
        kIndexNone, kIndexNone, kIndexFieldRef,
        kIndexFieldRef, kIndexFieldRef, kIndexFieldRef,
        kIndexFieldRef, kIndexFieldRef, kIndexFieldRef,
        kIndexFieldRef, kIndexFieldRef, kIndexUnknown,
        kIndexVaries, kIndexInlineMethod, kIndexInlineMethod,
        kIndexMethodRef, kIndexNone, kIndexFieldOffset,
        kIndexFieldOffset, kIndexFieldOffset, kIndexFieldOffset,
        kIndexFieldOffset, kIndexFieldOffset, kIndexVtableOffset,
        kIndexVtableOffset, kIndexVtableOffset, kIndexVtableOffset,
        kIndexFieldRef, kIndexFieldRef, kIndexFieldRef,
        kIndexUnknown,
        // END(libdex-index-types)
};

/* Helper for FETCH_u4, above. */
inline u4 fetch_u4_impl(u4 offset, const u2 *insns) {
    return insns[offset] | ((u4) insns[offset + 1] << 16);
}


#define FETCH(_offset)      (insns[(_offset)])
#define FETCH_u4(_offset)   (fetch_u4_impl((_offset), insns))
#define INST_A(_inst)       (((u2)(_inst) >> 8) & 0x0f)
#define INST_B(_inst)       ((u2)(_inst) >> 12)
#define INST_AA(_inst)      ((_inst) >> 8)



//dvm

/* fwd decl */
struct DataObject;
struct InitiatingLoaderList;
struct ClassObject;
struct StringObject;
struct ArrayObject;
struct Method;
struct ExceptionEntry;
struct LineNumEntry;
struct StaticField;
struct InstField;
struct Field;
struct RegisterMap;


/*
 * Native function pointer type.
 *
 * "args[0]" holds the "this" pointer for virtual methods.
 *
 * The "Bridge" form is a super-set of the "Native" form; in many places
 * they are used interchangeably.  Currently, all functions have all
 * arguments passed in, but some functions only care about the first two.
 * Passing extra arguments to a C function is (mostly) harmless.
 */
struct MemMapping {
    void *addr; /* start of data */
    uint length; /* length of data */

    void *baseAddr; /* page-aligned base address */
    uint baseLength; /* length of mapping */
};

struct DvmDex {
    /* pointer to the DexFile we're associated with */
    DexFile *pDexFile;

    /* clone of pDexFile->pHeader (it's used frequently enough) */
    const DexHeader *pHeader;

    /* interned strings; parallel to "stringIds" */
    struct StringObject **pResStrings;

    /* resolved classes; parallel to "typeIds" */
    struct ClassObject **pResClasses;

    /* resolved methods; parallel to "methodIds" */
    struct Method **pResMethods;

    /* resolved instance fields; parallel to "fieldIds" */
    /* (this holds both InstField and StaticField) */
    struct Field **pResFields;

    /* interface method lookup cache */
    struct AtomicCache *pInterfaceCache;

    /* shared memory region with file contents */
    bool isMappedReadOnly;
    MemMapping memMap;

    void *dex_object;

    /* lock ensuring mutual exclusion during updates */
    void *modLock;
};


struct Object;

union JValue {
    u1 z;
    s1 b;
    u2 c;
    s2 s;
    s4 i;
    s8 j;
    float f;
    double d;
    Object *l;
};

typedef void (*DalvikBridgeFunc)(const u4 *args, JValue *pResult,
                                 const Method *method, struct Thread *self);

/* vm-internal access flags and related definitions */
enum AccessFlags {
    ACC_MIRANDA = 0x8000, // method (internal to VM)
    JAVA_FLAGS_MASK = 0xffff, // bits set from Java sources (low 16)
};

typedef void (*DalvikNativeFunc)(const u4 *args, JValue *pResult);

/* Use the top 16 bits of the access flags field for
 * other class flags.  Code should use the *CLASS_FLAG*()
 * macros to set/get these flags.
 */
enum ClassFlags {
    CLASS_ISFINALIZABLE = (1 << 31), // class/ancestor overrides finalize()
    CLASS_ISARRAY = (1 << 30), // class is a "[*"
    CLASS_ISOBJECTARRAY = (1 << 29), // class is a "[L*" or "[[*"
    CLASS_ISCLASS = (1 << 28), // class is *the* class Class

    CLASS_ISREFERENCE = (1 << 27), // class is a soft/weak/phantom ref
    // only ISREFERENCE is set --> soft
            CLASS_ISWEAKREFERENCE = (1 << 26), // class is a weak reference
    CLASS_ISFINALIZERREFERENCE = (1 << 25), // class is a finalizer reference
    CLASS_ISPHANTOMREFERENCE = (1 << 24), // class is a phantom reference

    CLASS_MULTIPLE_DEFS = (1 << 23), // DEX verifier: defs in multiple DEXs

    /* unlike the others, these can be present in the optimized DEX file */
            CLASS_ISOPTIMIZED = (1 << 17), // class may contain opt instrs
    CLASS_ISPREVERIFIED = (1 << 16), // class has been pre-verified
};

/* bits we can reasonably expect to see set in a DEX access flags field */
#define EXPECTED_FILE_FLAGS \
    (ACC_CLASS_MASK | CLASS_ISPREVERIFIED | CLASS_ISOPTIMIZED)

/*
 * Get/set class flags.
 */
#define SET_CLASS_FLAG(clazz, flag) \
    do { (clazz)->accessFlags |= (flag); } while (0)

#define CLEAR_CLASS_FLAG(clazz, flag) \
    do { (clazz)->accessFlags &= ~(flag); } while (0)

#define IS_CLASS_FLAG_SET(clazz, flag) \
    (((clazz)->accessFlags & (flag)) != 0)

#define GET_CLASS_FLAG_GROUP(clazz, flags) \
    ((u4)((clazz)->accessFlags & (flags)))

/*
 * Use the top 16 bits of the access flags field for other method flags.
 * Code should use the *METHOD_FLAG*() macros to set/get these flags.
 */
enum MethodFlags {
    METHOD_ISWRITABLE = (1 << 31), // the method's code is writable
};

/*
 * Get/set method flags.
 */
#define SET_METHOD_FLAG(method, flag) \
    do { (method)->accessFlags |= (flag); } while (0)

#define CLEAR_METHOD_FLAG(method, flag) \
    do { (method)->accessFlags &= ~(flag); } while (0)

#define IS_METHOD_FLAG_SET(method, flag) \
    (((method)->accessFlags & (flag)) != 0)

#define GET_METHOD_FLAG_GROUP(method, flags) \
    ((u4)((method)->accessFlags & (flags)))

/* current state of the class, increasing as we progress */
enum ClassStatus {
    CLASS_ERROR = -1,

    CLASS_NOTREADY = 0,
    CLASS_IDX = 1, /* loaded, DEX idx in super or ifaces */
    CLASS_LOADED = 2, /* DEX idx values resolved */
    CLASS_RESOLVED = 3, /* part of linking */
    CLASS_VERIFYING = 4, /* in the process of being verified */
    CLASS_VERIFIED = 5, /* logically part of linking; done pre-init */
    CLASS_INITIALIZING = 6, /* class init in progress */
    CLASS_INITIALIZED = 7, /* ready to go */
};

/*
 * Definitions for packing refOffsets in ClassObject.
 */
/*
 * A magic value for refOffsets. Ignore the bits and walk the super
 * chain when this is the value.
 * [This is an unlikely "natural" value, since it would be 30 non-ref instance
 * fields followed by 2 ref instance fields.]
 */
#define CLASS_WALK_SUPER ((unsigned int)(3))
#define CLASS_SMALLEST_OFFSET (sizeof(struct Object))
#define CLASS_BITS_PER_WORD (sizeof(unsigned long int) * 8)
#define CLASS_OFFSET_ALIGNMENT 4
#define CLASS_HIGH_BIT ((unsigned int)1 << (CLASS_BITS_PER_WORD - 1))
/*
 * Given an offset, return the bit number which would encode that offset.
 * Local use only.
 */
#define _CLASS_BIT_NUMBER_FROM_OFFSET(byteOffset) \
    (((unsigned int)(byteOffset) - CLASS_SMALLEST_OFFSET) / \
     CLASS_OFFSET_ALIGNMENT)
/*
 * Is the given offset too large to be encoded?
 */
#define CLASS_CAN_ENCODE_OFFSET(byteOffset) \
    (_CLASS_BIT_NUMBER_FROM_OFFSET(byteOffset) < CLASS_BITS_PER_WORD)
/*
 * Return a single bit, encoding the offset.
 * Undefined if the offset is too large, as defined above.
 */
#define CLASS_BIT_FROM_OFFSET(byteOffset) \
    (CLASS_HIGH_BIT >> _CLASS_BIT_NUMBER_FROM_OFFSET(byteOffset))
/*
 * Return an offset, given a bit number as returned from CLZ.
 */
#define CLASS_OFFSET_FROM_CLZ(rshift) \
    (((int)(rshift) * CLASS_OFFSET_ALIGNMENT) + CLASS_SMALLEST_OFFSET)


/*
 * Used for iftable in ClassObject.
 */
struct InterfaceEntry {
    /* pointer to interface class */
    ClassObject *clazz;

    /*
     * Index into array of vtable offsets.  This points into the ifviPool,
     * which holds the vtables for all interfaces declared by this class.
     */
    int *methodIndexArray;
};


/*
 * There are three types of objects:
 *  Class objects - an instance of java.lang.Class
 *  Array objects - an object created with a "new array" instruction
 *  Data objects - an object that is neither of the above
 *
 * We also define String objects.  At present they're equivalent to
 * DataObject, but that may change.  (Either way, they make some of the
 * code more obvious.)
 *
 * All objects have an Object header followed by type-specific data.
 */
struct Object {
    /* ptr to class object */
    ClassObject *clazz;

    /*
     * A word containing either a "thin" lock or a "fat" monitor.  See
     * the comments in Sync.c for a description of its layout.
     */
    u4 lock;
};

/*
 * Properly initialize an Object.
 * void DVM_OBJECT_INIT(Object *obj, ClassObject *clazz_)
 */
#define DVM_OBJECT_INIT(obj, clazz_) \
    dvmSetFieldObject(obj, OFFSETOF_MEMBER(Object, clazz), clazz_)

/*
 * Data objects have an Object header followed by their instance data.
 */
struct DataObject : Object {
    /* variable #of u4 slots; u8 uses 2 slots */
    u4 instanceData[1];
};

/*
 * Strings are used frequently enough that we may want to give them their
 * own unique type.
 *
 * Using a dedicated type object to access the instance data provides a
 * performance advantage but makes the java/lang/String.java implementation
 * fragile.
 *
 * Currently this is just equal to DataObject, and we pull the fields out
 * like we do for any other object.
 */
struct StringObject : Object {
    /* variable #of u4 slots; u8 uses 2 slots */
    u4 instanceData[1];

    /** Returns this string's length in characters. */
    int length() const;

    /**
     * Returns this string's length in bytes when encoded as modified UTF-8.
     * Does not include a terminating NUL byte.
     */
    int utfLength() const;

    /** Returns this string's char[] as an ArrayObject. */
    ArrayObject *array() const;

    /** Returns this string's char[] as a u2*. */
    const u2 *chars() const;
};


/*
 * Array objects have these additional fields.
 *
 * We don't currently store the size of each element.  Usually it's implied
 * by the instruction.  If necessary, the width can be derived from
 * the first char of obj->clazz->descriptor.
 */
struct ArrayObject : Object {
    /* number of elements; immutable after init */
    u4 length;

    /*
     * Array contents; actual size is (length * sizeof(type)).  This is
     * declared as u8 so that the compiler inserts any necessary padding
     * (e.g. for EABI); the actual allocation may be smaller than 8 bytes.
     */
    u8 contents[1];
};

/*
 * For classes created early and thus probably in the zygote, the
 * InitiatingLoaderList is kept in gDvm. Later classes use the structure in
 * Object Class. This helps keep zygote pages shared.
 */
struct InitiatingLoaderList {
    /* a list of initiating loader Objects; grown and initialized on demand */
    Object **initiatingLoaders;
    /* count of loaders in the above list */
    int initiatingLoaderCount;
};

/*
 * Generic field header.  We pass this around when we want a generic Field
 * pointer (e.g. for reflection stuff).  Testing the accessFlags for
 * ACC_STATIC allows a proper up-cast.
 */
struct Field {
    ClassObject *clazz; /* class in which the field is declared */
    const char *name;
    const char *signature; /* e.g. "I", "[C", "Landroid/os/Debug;" */
    u4 accessFlags;
};

/*
 * Static field.
 */
struct StaticField : Field {
    JValue value; /* initially set from DEX for primitives */
};

/*
 * Instance field.
 */
struct InstField : Field {
    /*
     * This field indicates the byte offset from the beginning of the
     * (Object *) to the actual instance data; e.g., byteOffset==0 is
     * the same as the object pointer (bug!), and byteOffset==4 is 4
     * bytes farther.
     */
    int byteOffset;
};

/*
 * This defines the amount of space we leave for field slots in the
 * java.lang.Class definition.  If we alter the class to have more than
 * this many fields, the VM will abort at startup.
 */
#define CLASS_FIELD_SLOTS   4

/*
 * Class objects have many additional fields.  This is used for both
 * classes and interfaces, including synthesized classes (arrays and
 * primitive types).
 *
 * Class objects are unusual in that they have some fields allocated with
 * the system malloc (or LinearAlloc), rather than on the GC heap.  This is
 * handy during initialization, but does require special handling when
 * discarding java.lang.Class objects.
 *
 * The separation of methods (direct vs. virtual) and fields (class vs.
 * instance) used in Dalvik works out pretty well.  The only time it's
 * annoying is when enumerating or searching for things with reflection.
 */
struct ClassObject : Object {
    /* leave space for instance data; we could access fields directly if we
       freeze the definition of java/lang/Class */
    u4 instanceData[CLASS_FIELD_SLOTS];

    /* UTF-8 descriptor for the class; from constant pool, or on heap
       if generated ("[C") */
    const char *descriptor;
    char *descriptorAlloc;

    /* access flags; low 16 bits are defined by VM spec */
    u4 accessFlags;

    /* VM-unique class serial number, nonzero, set very early */
    u4 serialNumber;

    DvmDex *pDvmDex;

    /* state of class initialization */
    ClassStatus status;

    /* if class verify fails, we must return same error on subsequent tries */
    ClassObject *verifyErrorClass;

    /* threadId, used to check for recursive <clinit> invocation */
    u4 initThreadId;

    /*
     * Total object size; used when allocating storage on gc heap.  (For
     * interfaces and abstract classes this will be zero.)
     */
    size_t objectSize;

    /* arrays only: class object for base element, for instanceof/checkcast
       (for String[][][], this will be String) */
    ClassObject *elementClass;

    /* arrays only: number of dimensions, e.g. int[][] is 2 */
    int arrayDim;

    /* primitive type index, or PRIM_NOT (-1); set for generated prim classes */
    PrimitiveType primitiveType;

    /* superclass, or NULL if this is java.lang.Object */
    ClassObject *super;

    /* defining class loader, or NULL for the "bootstrap" system loader */
    Object *classLoader;

    /* initiating class loader list */
    /* NOTE: for classes with low serialNumber, these are unused, and the
       values are kept in a table in gDvm. */
    InitiatingLoaderList initiatingLoaderList;

    /* array of interfaces this class implements directly */
    int interfaceCount;
    ClassObject **interfaces;

    /* static, private, and <init> methods */
    int directMethodCount;
    Method *directMethods;

    /* virtual methods defined in this class; invoked through vtable */
    int virtualMethodCount;
    Method *virtualMethods;

    /*
     * Virtual method table (vtable), for use by "invoke-virtual".  The
     * vtable from the superclass is copied in, and virtual methods from
     * our class either replace those from the super or are appended.
     */
    int vtableCount;
    Method **vtable;

    /*
     * Interface table (iftable), one entry per interface supported by
     * this class.  That means one entry for each interface we support
     * directly, indirectly via superclass, or indirectly via
     * superinterface.  This will be null if neither we nor our superclass
     * implement any interfaces.
     *
     * Why we need this: given "class Foo implements Face", declare
     * "Face faceObj = new Foo()".  Invoke faceObj.blah(), where "blah" is
     * part of the Face interface.  We can't easily use a single vtable.
     *
     * For every interface a concrete class implements, we create a list of
     * virtualMethod indices for the methods in the interface.
     */
    int iftableCount;
    InterfaceEntry *iftable;

    /*
     * The interface vtable indices for iftable get stored here.  By placing
     * them all in a single pool for each class that implements interfaces,
     * we decrease the number of allocations.
     */
    int ifviPoolCount;
    int *ifviPool;

    /* instance fields
     *
     * These describe the layout of the contents of a DataObject-compatible
     * Object.  Note that only the fields directly defined by this class
     * are listed in ifields;  fields defined by a superclass are listed
     * in the superclass's ClassObject.ifields.
     *
     * All instance fields that refer to objects are guaranteed to be
     * at the beginning of the field list.  ifieldRefCount specifies
     * the number of reference fields.
     */
    int ifieldCount;
    int ifieldRefCount; // number of fields that are object refs
    InstField *ifields;

    /* bitmap of offsets of ifields */
    u4 refOffsets;

    /* source file name, if known */
    const char *sourceFile;

    /* static fields */
    int sfieldCount;
    StaticField sfields[]; /* MUST be last item */
};

/*
 * A method.  We create one of these for every method in every class
 * we load, so try to keep the size to a minimum.
 *
 * Much of this comes from and could be accessed in the data held in shared
 * memory.  We hold it all together here for speed.  Everything but the
 * pointers could be held in a shared table generated by the optimizer;
 * if we're willing to convert them to offsets and take the performance
 * hit (e.g. "meth->insns" becomes "baseAddr + meth->insnsOffset") we
 * could move everything but "nativeFunc".
 */
struct DexProto {
    const DexFile *dexFile; /* file the idx refers to */
    u4 protoIdx; /* index into proto_ids table of dexFile */
};

struct Method {
    /* the class we are a part of */
    ClassObject *clazz;

    /* access flags; low 16 bits are defined by spec (could be u2?) */
    u4 accessFlags;

    /*
     * For concrete virtual methods, this is the offset of the method
     * in "vtable".
     *
     * For abstract methods in an interface class, this is the offset
     * of the method in "iftable[n]->methodIndexArray".
     */
    u2 methodIndex;

    /*
     * Method bounds; not needed for an abstract method.
     *
     * For a native method, we compute the size of the argument list, and
     * set "insSize" and "registerSize" equal to it.
     */
    u2 registersSize; /* ins + locals */
    u2 outsSize;
    u2 insSize;

    /* method name, e.g. "<init>" or "eatLunch" */
    const char *name;

    /*
     * Method prototype descriptor string (return and argument types).
     *
     * TODO: This currently must specify the DexFile as well as the proto_ids
     * index, because generated Proxy classes don't have a DexFile.  We can
     * remove the DexFile* and reduce the size of this struct if we generate
     * a DEX for proxies.
     */
    DexProto prototype;

    /* short-form method descriptor string */
    const char *shorty;

    /*
     * The remaining items are not used for abstract or native methods.
     * (JNI is currently hijacking "insns" as a function pointer, set
     * after the first call.  For internal-native this stays null.)
     */

    /* the actual code */
    const u2 *insns; /* instructions, in memory-mapped .dex */

    /* JNI: cached argument and return-type hints */
    int jniArgInfo;

    /*
     * JNI: native method ptr; could be actual function or a JNI bridge.  We
     * don't currently discriminate between DalvikBridgeFunc and
     * DalvikNativeFunc; the former takes an argument superset (i.e. two
     * extra args) which will be ignored.  If necessary we can use
     * insns==NULL to detect JNI bridge vs. internal native.
     */
    void *nativeFunc;

    /*
     * JNI: true if this static non-synchronized native method (that has no
     * reference arguments) needs a JNIEnv* and jclass/jobject. Libcore
     * uses this.
     */
    bool fastJni;

    /*
     * JNI: true if this method has no reference arguments. This lets the JNI
     * bridge avoid scanning the shorty for direct pointers that need to be
     * converted to local references.
     *
     * TODO: replace this with a list of indexes of the reference arguments.
     */
    bool noRef;

    /*
     * JNI: true if we should log entry and exit. This is the only way
     * developers can log the local references that are passed into their code.
     * Used for debugging JNI problems in third-party code.
     */
    bool shouldTrace;

    /*
     * Register map data, if available.  This will point into the DEX file
     * if the data was computed during pre-verification, or into the
     * linear alloc area if not.
     */
    const RegisterMap *registerMap;

    /* set if method was called during method profiling */
    bool inProfile;
};


//-===========================art 相关定义=============================
#include <stdint.h>
#include <cassert>
#include <sys/types.h>

class Object_API21 {
public:
    uint32_t klass_;

    uint32_t monitor_;
};

class DexCache_API21 : public Object_API21 {
public:
    uint32_t dex_;
    uint32_t location_;
    uint32_t resolved_fields_;
    uint32_t resolved_methods_;
    uint32_t resolved_types_;
    uint32_t strings_;
    uint64_t dex_file_;
};

class Class_API21 : public Object_API21 {
public:

    uint32_t class_loader_;
    // For array classes, the component class object for instanceof/checkcast
    // (for String[][][], this will be String[][]). NULL for non-array classes.
    uint32_t component_type_;
    // DexCache of resolved constant pool entries (will be NULL for classes generated by the
    // runtime such as arrays and primitive classes).
    uint32_t dex_cache_;
    // static, private, and <init> methods
    uint32_t direct_methods_;
    // instance fields
    //
    // These describe the layout of the contents of an Object.
    // Note that only the fields directly declared by this class are
    // listed in ifields; fields declared by a superclass are listed in
    // the superclass's Class.ifields.
    //
    // All instance fields that refer to objects are guaranteed to be at
    // the beginning of the field list.  num_reference_instance_fields_
    // specifies the number of reference fields.
    uint32_t ifields_;
    // The interface table (iftable_) contains pairs of a interface class and an array of the
    // interface methods. There is one pair per interface supported by this class.  That means one
    // pair for each interface we support directly, indirectly via superclass, or indirectly via a
    // superinterface.  This will be null if neither we nor our superclass implement any interfaces.
    //
    // Why we need this: given "class Foo implements Face", declare "Face faceObj = new Foo()".
    // Invoke faceObj.blah(), where "blah" is part of the Face interface.  We can't easily use a
    // single vtable.
    //
    // For every interface a concrete class implements, we create an array of the concrete vtable_
    // methods for the methods in the interface.
    uint32_t iftable_;
    // Interface method table (imt), for quick "invoke-interface".
    uint32_t imtable_;
    // Descriptor for the class such as "java.lang.Class" or "[C". Lazily initialized by ComputeName
    uint32_t name_;
    // Static fields
    uint32_t sfields_;
    // The superclass, or NULL if this is java.lang.Object, an interface or primitive type.
    uint32_t super_class_;
    // If class verify fails, we must return same error on subsequent tries.
    uint32_t verify_error_class_;
    // Virtual methods defined in this class; invoked through vtable.
    uint32_t virtual_methods_;
    // Virtual method table (vtable), for use by "invoke-virtual".  The vtable from the superclass is
    // copied in, and virtual methods from our class either replace those from the super or are
    // appended. For abstract classes, methods may be created in the vtable that aren't in
    // virtual_ methods_ for miranda methods.
    uint32_t vtable_;
    // Access flags; low 16 bits are defined by VM spec.
    uint32_t access_flags_;
    // Total size of the Class instance; used when allocating storage on gc heap.
    // See also object_size_.
    uint32_t class_size_;
    // Tid used to check for recursive <clinit> invocation.
    pid_t clinit_thread_id_;
    // ClassDef index in dex file, -1 if no class definition such as an array.
    // TODO: really 16bits
    int32_t dex_class_def_idx_;
    // Type index in dex file.
    // TODO: really 16bits
    int32_t dex_type_idx_;
    // Number of instance fields that are object refs.
    uint32_t num_reference_instance_fields_;
    // Number of static fields that are object refs,
    uint32_t num_reference_static_fields_;
    // Total object size; used when allocating storage on gc heap.
    // (For interfaces and abstract classes this will be zero.)
    // See also class_size_.
    uint32_t object_size_;
    // Primitive type value, or Primitive::kPrimNot (0); set for generated primitive classes.
    uint32_t primitive_type_;
    // Bitmap of offsets of ifields.
    uint32_t reference_instance_offsets_;
    // Bitmap of offsets of sfields.
    uint32_t reference_static_offsets_;
    // State of class initialization.
    int32_t status_;
    // TODO: ?
    // initiating class loader list
    // NOTE: for classes with low serialNumber, these are unused, and the
    // values are kept in a table in gDvm.
    // InitiatingLoaderList initiating_loader_list_;
    // The following data exist in real class objects.
    // Embedded Imtable, for class object that's not an interface, fixed size.
    uint32_t embedded_imtable_[0];
    // Embedded Vtable, for class object that's not an interface, variable size.
    uint32_t embedded_vtable_[0];
    // Static fields, variable size.
    uint32_t fields_[0];

};

class ArtField_API21 : public Object_API21 {
public:
    uint32_t declaring_class_;
    uint32_t access_flags_;
    uint32_t field_dex_idx_;
    uint32_t offset_;
};

class ArtMethod_API21 : public Object_API21 {
public:
    // Field order required by test "ValidateFieldOrderOfJavaCppUnionClasses".
    // The class we are a part of
    uint32_t declaring_class_;

    // short cuts to declaring_class_->dex_cache_ member for fast compiled code access
    uint32_t dex_cache_resolved_methods_;

    // short cuts to declaring_class_->dex_cache_ member for fast compiled code access
    uint32_t dex_cache_resolved_types_;

    // short cuts to declaring_class_->dex_cache_ member for fast compiled code access
    uint32_t dex_cache_strings_;

    // Method dispatch from the interpreter invokes this pointer which may cause a bridge into
    // compiled code.
    uint64_t entry_point_from_interpreter_;

    // Pointer to JNI function registered to this method, or a function to resolve the JNI function.
    uint64_t entry_point_from_jni_;

    // Method dispatch from portable compiled code invokes this pointer which may cause bridging into
    // quick compiled code or the interpreter.
#if defined(ART_USE_PORTABLE_COMPILER)
    uint64_t entry_point_from_portable_compiled_code_;
#endif

    // Method dispatch from quick compiled code invokes this pointer which may cause bridging into
    // portable compiled code or the interpreter.
    uint64_t entry_point_from_quick_compiled_code_;

    // Pointer to a data structure created by the compiler and used by the garbage collector to
    // determine which registers hold live references to objects within the heap. Keyed by native PC
    // offsets for the quick compiler and dex PCs for the portable.
    uint64_t gc_map_;

    // Access flags; low 16 bits are defined by spec.
    uint32_t access_flags_;

    /* Dex file fields. The defining dex file is available via declaring_class_->dex_cache_ */

    // Offset to the CodeItem.
    uint32_t dex_code_item_offset_;

    // Index into method_ids of the dex file associated with this method.
    uint32_t dex_method_index_;

    /* End of dex file fields. */

    // Entry within a dispatch table for this method. For static/direct methods the index is into
    // the declaringClass.directMethods, for virtual methods the vtable and for interface methods the
    // ifTable.
    uint32_t method_index_;

};


class Object_API22 {
public:
    uint32_t klass_;
    uint32_t monitor_;
};

class DexCache_API22 : public Object_API22 {
public:
    uint32_t dex_;
    uint32_t location_;
    uint32_t resolved_fields_;
    uint32_t resolved_methods_;
    uint32_t resolved_types_;
    uint32_t strings_;
    uint64_t dex_file_;
};

class Class_API22 : public Object_API22 {
public:
    uint32_t class_loader_;
    uint32_t component_type_;
    uint32_t dex_cache_;
    uint32_t dex_cache_strings_;
    // static, private, and <init> methods
    uint32_t direct_methods_;
    // instance fields
    //
    // These describe the layout of the contents of an Object.
    // Note that only the fields directly declared by this class are
    // listed in ifields; fields declared by a superclass are listed in
    // the superclass's Class.ifields.
    //
    // All instance fields that refer to objects are guaranteed to be at
    // the beginning of the field list.  num_reference_instance_fields_
    // specifies the number of reference fields.
    uint32_t ifields_;
    // The interface table (iftable_) contains pairs of a interface class and an array of the
    // interface methods. There is one pair per interface supported by this class.  That means one
    // pair for each interface we support directly, indirectly via superclass, or indirectly via a
    // superinterface.  This will be null if neither we nor our superclass implement any interfaces.
    //
    // Why we need this: given "class Foo implements Face", declare "Face faceObj = new Foo()".
    // Invoke faceObj.blah(), where "blah" is part of the Face interface.  We can't easily use a
    // single vtable.
    //
    // For every interface a concrete class implements, we create an array of the concrete vtable_
    // methods for the methods in the interface.
    uint32_t iftable_;
    // Descriptor for the class such as "java.lang.Class" or "[C". Lazily initialized by ComputeName
    uint32_t name_;
    // Static fields
    uint32_t sfields_;
    // The superclass, or NULL if this is java.lang.Object, an interface or primitive type.
    uint32_t super_class_;
    // If class verify fails, we must return same error on subsequent tries.
    uint32_t verify_error_class_;
    // Virtual methods defined in this class; invoked through vtable.
    uint32_t virtual_methods_;
    // Virtual method table (vtable), for use by "invoke-virtual".  The vtable from the superclass is
    // copied in, and virtual methods from our class either replace those from the super or are
    // appended. For abstract classes, methods may be created in the vtable that aren't in
    // virtual_ methods_ for miranda methods.
    uint32_t vtable_;
    // Access flags; low 16 bits are defined by VM spec.
    uint32_t access_flags_;
    // Total size of the Class instance; used when allocating storage on gc heap.
    // See also object_size_.
    uint32_t class_size_;
    // Tid used to check for recursive <clinit> invocation.
    pid_t clinit_thread_id_;
    // ClassDef index in dex file, -1 if no class definition such as an array.
    // TODO: really 16bits
    int32_t dex_class_def_idx_;
    // Type index in dex file.
    // TODO: really 16bits
    int32_t dex_type_idx_;
    // Number of instance fields that are object refs.
    uint32_t num_reference_instance_fields_;
    // Number of static fields that are object refs,
    uint32_t num_reference_static_fields_;
    // Total object size; used when allocating storage on gc heap.
    // (For interfaces and abstract classes this will be zero.)
    // See also class_size_.
    uint32_t object_size_;
    // Primitive type value, or Primitive::kPrimNot (0); set for generated primitive classes.
    uint32_t primitive_type_;
    // Bitmap of offsets of ifields.
    uint32_t reference_instance_offsets_;
    // Bitmap of offsets of sfields.
    uint32_t reference_static_offsets_;
    // State of class initialization.
    int32_t status_;

};

class ArtField_API22 : public Object_API22 {
public:
    uint32_t declaring_class_;
    int32_t access_flags_;
    int32_t field_dex_idx_;
    int32_t offset_;
};

class ArtMethod_API22 : public Object_API22 {
public:
    // Field order required by test "ValidateFieldOrderOfJavaCppUnionClasses".
    // The class we are a part of.
    uint32_t declaring_class_;
    // Short cuts to declaring_class_->dex_cache_ member for fast compiled code access.
    uint32_t dex_cache_resolved_methods_;
    // Short cuts to declaring_class_->dex_cache_ member for fast compiled code access.
    uint32_t dex_cache_resolved_types_;
    // Access flags; low 16 bits are defined by spec.
    uint32_t access_flags_;
    /* Dex file fields. The defining dex file is available via declaring_class_->dex_cache_ */
    // Offset to the CodeItem.
    uint32_t dex_code_item_offset_;
    // Index into method_ids of the dex file associated with this method.
    uint32_t dex_method_index_;
    /* End of dex file fields. */
    // Entry within a dispatch table for this method. For static/direct methods the index is into
    // the declaringClass.directMethods, for virtual methods the vtable and for interface methods the
    // ifTable.
    uint32_t method_index_;

    // Fake padding field gets inserted here.
    // Must be the last fields in the method.
    struct PtrSizedFields {
        // Method dispatch from the interpreter invokes this pointer which may cause a bridge into
        // compiled code.
        void *entry_point_from_interpreter_;
        // Pointer to JNI function registered to this method, or a function to resolve the JNI function.
        void *entry_point_from_jni_;
        // Method dispatch from quick compiled code invokes this pointer which may cause bridging into
        // portable compiled code or the interpreter.
        void *entry_point_from_quick_compiled_code_;
    } ptr_sized_fields_;

};

class Object_API23 {
public:
    uint32_t klass_;

    uint32_t monitor_;
};

class DexFileArt {
public:
    uint32_t temp;
    u1 *data;
    uint32_t len;
};

class DexCache_API23 : public Object_API23 {
public:
    uint32_t dex_;
    uint32_t location_;
    uint32_t resolved_fields_;
    uint32_t resolved_methods_;
    uint32_t resolved_types_;
    uint32_t strings_;
    uint64_t dex_file_;
};

class Class_API23 : public Object_API23 {
public:
    uint32_t class_loader_;
    // For array classes, the component class object for instanceof/checkcast
    // (for String[][][], this will be String[][]). null for non-array classes.
    uint32_t component_type_;
    // DexCache of resolved constant pool entries (will be null for classes generated by the
    // runtime such as arrays and primitive classes).
    uint32_t dex_cache_;
    // Short cuts to dex_cache_ member for fast compiled code access.
    uint32_t dex_cache_strings_;
    // The interface table (iftable_) contains pairs of a interface class and an array of the
    // interface methods. There is one pair per interface supported by this class.  That means one
    // pair for each interface we support directly, indirectly via superclass, or indirectly via a
    // superinterface.  This will be null if neither we nor our superclass implement any interfaces.
    //
    // Why we need this: given "class Foo implements Face", declare "Face faceObj = new Foo()".
    // Invoke faceObj.blah(), where "blah" is part of the Face interface.  We can't easily use a
    // single vtable.
    //
    // For every interface a concrete class implements, we create an array of the concrete vtable_
    // methods for the methods in the interface.
    uint32_t iftable_;
    // Descriptor for the class such as "java.lang.Class" or "[C". Lazily initialized by ComputeName
    uint32_t name_;
    // The superclass, or null if this is java.lang.Object or a primitive type.
    //
    // Note that interfaces have java.lang.Object as their
    // superclass. This doesn't match the expectations in JNI
    // GetSuperClass or java.lang.Class.getSuperClass() which need to
    // check for interfaces and return null.
    uint32_t super_class_;
    // If class verify fails, we must return same error on subsequent tries.
    uint32_t verify_error_class_;
    // Virtual method table (vtable), for use by "invoke-virtual".  The vtable from the superclass is
    // copied in, and virtual methods from our class either replace those from the super or are
    // appended. For abstract classes, methods may be created in the vtable that aren't in
    // virtual_ methods_ for miranda methods.
    uint32_t vtable_;
    // Access flags; low 16 bits are defined by VM spec.
    // Note: Shuffled back.
    uint32_t access_flags_;
    // static, private, and <init> methods. Pointer to an ArtMethod length-prefixed array.
    uint64_t direct_methods_;
    // instance fields
    //
    // These describe the layout of the contents of an Object.
    // Note that only the fields directly declared by this class are
    // listed in ifields; fields declared by a superclass are listed in
    // the superclass's Class.ifields.
    //
    // ArtFields are allocated as a length prefixed ArtField array, and not an array of pointers to
    // ArtFields.
    uint64_t ifields_;
    // Static fields length-prefixed array.
    uint64_t sfields_;
    // Virtual methods defined in this class; invoked through vtable. Pointer to an ArtMethod
    // length-prefixed array.
    uint64_t virtual_methods_;
    // Total size of the Class instance; used when allocating storage on gc heap.
    // See also object_size_.
    uint32_t class_size_;
    // Tid used to check for recursive <clinit> invocation.
    pid_t clinit_thread_id_;
    // ClassDef index in dex file, -1 if no class definition such as an array.
    // TODO: really 16bits
    int32_t dex_class_def_idx_;
    // Type index in dex file.
    // TODO: really 16bits
    int32_t dex_type_idx_;
    // Number of direct fields.
    uint32_t num_direct_methods_;
    // Number of instance fields.
    uint32_t num_instance_fields_;
    // Number of instance fields that are object refs.
    uint32_t num_reference_instance_fields_;
    // Number of static fields that are object refs,
    uint32_t num_reference_static_fields_;
    // Number of static fields.
    uint32_t num_static_fields_;
    // Number of virtual methods.
    uint32_t num_virtual_methods_;
    // Total object size; used when allocating storage on gc heap.
    // (For interfaces and abstract classes this will be zero.)
    // See also class_size_.
    uint32_t object_size_;
    // The lower 16 bits contains a Primitive::Type value. The upper 16
    // bits contains the size shift of the primitive type.
    uint32_t primitive_type_;
    // Bitmap of offsets of ifields.
    uint32_t reference_instance_offsets_;
    // State of class initialization.
    uint32_t status_;
};

class ArtField_API23 {
public:
    uint32_t declaring_class_;
    uint32_t access_flags_;
    uint32_t field_dex_idx_;
    uint32_t offset_;
};

class ArtMethod_API23 {
public:

    // Field order required by test "ValidateFieldOrderOfJavaCppUnionClasses".
    // The class we are a part of.
    uint32_t declaring_class_;
    // Short cuts to declaring_class_->dex_cache_ member for fast compiled code access.
    uint32_t dex_cache_resolved_methods_;
    // Short cuts to declaring_class_->dex_cache_ member for fast compiled code access.
    uint32_t dex_cache_resolved_types_;
    // Access flags; low 16 bits are defined by spec.
    uint32_t access_flags_;
    /* Dex file fields. The defining dex file is available via declaring_class_->dex_cache_ */
    // Offset to the CodeItem.
    uint32_t dex_code_item_offset_;
    // Index into method_ids of the dex file associated with this method.
    uint32_t dex_method_index_;
    /* End of dex file fields. */
    // Entry within a dispatch table for this method. For static/direct methods the index is into
    // the declaringClass.directMethods, for virtual methods the vtable and for interface methods the
    // ifTable.
    uint32_t method_index_;

    // Fake padding field gets inserted here.
    // Must be the last fields in the method.
    // PACKED(4) is necessary for the correctness of
    // RoundUp(OFFSETOF_MEMBER(ArtMethod, ptr_sized_fields_), pointer_size).
    struct PtrSizedFields {
        // Method dispatch from the interpreter invokes this pointer which may cause a bridge into
        // compiled code.
        void *entry_point_from_interpreter_;
        // Pointer to JNI function registered to this method, or a function to resolve the JNI function.
        void *entry_point_from_jni_;
        // Method dispatch from quick compiled code invokes this pointer which may cause bridging into
        // the interpreter.
        void *entry_point_from_quick_compiled_code_;
    } ptr_sized_fields_;
};


class Object_API24 {
public:
    uint32_t klass_;

    uint32_t monitor_;
};

class DexCache_API24 : public Object_API24 {
public:
    uint32_t dex_;
    uint32_t location_;
    uint64_t dex_file_;           // const DexFile*
    uint64_t resolved_fields_;    // ArtField*, array with num_resolved_fields_ elements.
    uint64_t resolved_methods_;   // ArtMethod*, array with num_resolved_methods_ elements.
    uint64_t resolved_types_;     // GcRoot<Class>*, array with num_resolved_types_ elements.
    uint64_t strings_;            // GcRoot<String>*, array with num_strings_ elements.
    uint32_t num_resolved_fields_;    // Number of elements in the resolved_fields_ array.
    uint32_t num_resolved_methods_;   // Number of elements in the resolved_methods_ array.
    uint32_t num_resolved_types_;     // Number of elements in the resolved_types_ array.
    uint32_t num_strings_;            // Number of elements in the strings_ array.
};

class Class_API24 : public Object_API24 {
public:
    uint32_t annotation_type_;

    // Defining class loader, or null for the "bootstrap" system loader.
    uint32_t class_loader_;
    // For array classes, the component class object for instanceof/checkcast
    // (for String[][][], this will be String[][]). null for non-array classes.
    uint32_t component_type_;
    // DexCache of resolved constant pool entries (will be null for classes generated by the
    // runtime such as arrays and primitive classes).
    uint32_t dex_cache_;
    // The interface table (iftable_) contains pairs of a interface class and an array of the
    // interface methods. There is one pair per interface supported by this class.  That means one
    // pair for each interface we support directly, indirectly via superclass, or indirectly via a
    // superinterface.  This will be null if neither we nor our superclass implement any interfaces.
    //
    // Why we need this: given "class Foo implements Face", declare "Face faceObj = new Foo()".
    // Invoke faceObj.blah(), where "blah" is part of the Face interface.  We can't easily use a
    // single vtable.
    //
    // For every interface a concrete class implements, we create an array of the concrete vtable_
    // methods for the methods in the interface.
    uint32_t iftable_;
    // Descriptor for the class such as "java.lang.Class" or "[C". Lazily initialized by ComputeName
    uint32_t name_;
    // The superclass, or null if this is java.lang.Object or a primitive type.
    //
    // Note that interfaces have java.lang.Object as their
    // superclass. This doesn't match the expectations in JNI
    // GetSuperClass or java.lang.Class.getSuperClass() which need to
    // check for interfaces and return null.
    uint32_t super_class_;

    // If class verify fails, we must return same error on subsequent tries. We may store either
    // the class of the error, or an actual instance of Throwable here.
    uint32_t verify_error_;
    // Virtual method table (vtable), for use by "invoke-virtual".  The vtable from the superclass is
    // copied in, and virtual methods from our class either replace those from the super or are
    // appended. For abstract classes, methods may be created in the vtable that aren't in
    // virtual_ methods_ for miranda methods.
    uint32_t vtable_;
    // Access flags; low 16 bits are defined by VM spec.
    // Note: Shuffled back.
    uint32_t access_flags_;
    // Short cuts to dex_cache_ member for fast compiled code access.
    uint64_t dex_cache_strings_;

    // instance fields
    //
    // These describe the layout of the contents of an Object.
    // Note that only the fields directly declared by this class are
    // listed in ifields; fields declared by a superclass are listed in
    // the superclass's Class.ifields.
    //
    // ArtFields are allocated as a length prefixed ArtField array, and not an array of pointers to
    // ArtFields.
    uint64_t ifields_;
    // Pointer to an ArtMethod length-prefixed array. All the methods where this class is the place
    // where they are logically defined. This includes all private, static, final and virtual methods
    // as well as inherited default methods and miranda methods.
    //
    // The slice methods_ [0, virtual_methods_offset_) are the direct (static, private, init) methods
    // declared by this class.
    //
    // The slice methods_ [virtual_methods_offset_, copied_methods_offset_) are the virtual methods
    // declared by this class.
    //
    // The slice methods_ [copied_methods_offset_, |methods_|) are the methods that are copied from
    // interfaces such as miranda or default methods. These are copied for resolution purposes as this
    // class is where they are (logically) declared as far as the virtual dispatch is concerned.
    //
    // Note that this field is used by the native debugger as the unique identifier for the type.
    uint64_t methods_;

    // Static fields length-prefixed array.
    uint64_t sfields_;

    // Class flags to help speed up visiting object references.
    uint32_t class_flags_;

    // Total size of the Class instance; used when allocating storage on gc heap.
    // See also object_size_.
    uint32_t class_size_;
    // Tid used to check for recursive <clinit> invocation.
    pid_t clinit_thread_id_;
    // ClassDef index in dex file, -1 if no class definition such as an array.
    // TODO: really 16bits
    int32_t dex_class_def_idx_;
    // Type index in dex file.
    // TODO: really 16bits
    int32_t dex_type_idx_;
    // Number of instance fields that are object refs.
    uint32_t num_reference_instance_fields_;
    // Number of static fields that are object refs,
    uint32_t num_reference_static_fields_;
    // Total object size; used when allocating storage on gc heap.
    // (For interfaces and abstract classes this will be zero.)
    // See also class_size_.
    uint32_t object_size_;
    // The lower 16 bits contains a Primitive::Type value. The upper 16
    // bits contains the size shift of the primitive type.
    uint32_t primitive_type_;
    // Bitmap of offsets of ifields.
    uint32_t reference_instance_offsets_;
    // State of class initialization.
    uint32_t status_;
    // The offset of the first virtual method that is copied from an interface. This includes miranda,
    // default, and default-conflict methods. Having a hard limit of ((2 << 16) - 1) for methods
    // defined on a single class is well established in Java so we will use only uint16_t's here.
    uint16_t copied_methods_offset_;

    // The offset of the first declared virtual methods in the methods_ array.
    uint16_t virtual_methods_offset_;

};

class ArtField_API24 {
public:
    uint32_t declaring_class_;
    uint32_t access_flags_;
    uint32_t field_dex_idx_;
    uint32_t offset_;
};

class ArtMethod_API24 {
public:

    // Field order required by test "ValidateFieldOrderOfJavaCppUnionClasses".
    // The class we are a part of.
    uint32_t declaring_class_;
    // Access flags; low 16 bits are defined by spec.
    uint32_t access_flags_;
    /* Dex file fields. The defining dex file is available via declaring_class_->dex_cache_ */
    // Offset to the CodeItem.
    uint32_t dex_code_item_offset_;
    // Index into method_ids of the dex file associated with this method.
    uint32_t dex_method_index_;
    /* End of dex file fields. */
    // Entry within a dispatch table for this method. For static/direct methods the index is into
    // the declaringClass.directMethods, for virtual methods the vtable and for interface methods the
    // ifTable.
    uint16_t method_index_;

    // The hotness we measure for this method. Incremented by the interpreter. Not atomic, as we allow
    // missing increments: if the method is hot, we will see it eventually.
    uint16_t hotness_count_;

    // Fake padding field gets inserted here.
    // Must be the last fields in the method.
    // PACKED(4) is necessary for the correctness of
    // RoundUp(OFFSETOF_MEMBER(ArtMethod, ptr_sized_fields_), pointer_size).
    struct PtrSizedFields {
        // Short cuts to declaring_class_->dex_cache_ member for fast compiled code access.
        ArtMethod_API24 **dex_cache_resolved_methods_;

        // Short cuts to declaring_class_->dex_cache_ member for fast compiled code access.
        void *dex_cache_resolved_types_;

        // Pointer to JNI function registered to this method, or a function to resolve the JNI function,
        // or the profiling data for non-native methods, or an ImtConflictTable.
        void *entry_point_from_jni_;

        // Method dispatch from quick compiled code invokes this pointer which may cause bridging into
        // the interpreter.
        void *entry_point_from_quick_compiled_code_;
    } ptr_sized_fields_;
};


class Object_API25 {
public:
    uint32_t klass_;

    uint32_t monitor_;
};

class DexCache_API25 : public Object_API25 {
public:
    uint32_t dex_;
    uint32_t location_;
    uint64_t dex_file_;           // const DexFile*
    uint64_t resolved_fields_;    // ArtField*, array with num_resolved_fields_ elements.
    uint64_t resolved_methods_;   // ArtMethod*, array with num_resolved_methods_ elements.
    uint64_t resolved_types_;     // GcRoot<Class>*, array with num_resolved_types_ elements.
    uint64_t strings_;            // GcRoot<String>*, array with num_strings_ elements.
    uint32_t num_resolved_fields_;    // Number of elements in the resolved_fields_ array.
    uint32_t num_resolved_methods_;   // Number of elements in the resolved_methods_ array.
    uint32_t num_resolved_types_;     // Number of elements in the resolved_types_ array.
    uint32_t num_strings_;            // Number o
};

class Class_API25 : public Object_API25 {
public:
    uint32_t annotation_type_;

    // Defining class loader, or null for the "bootstrap" system loader.
    uint32_t class_loader_;
    // For array classes, the component class object for instanceof/checkcast
    // (for String[][][], this will be String[][]). null for non-array classes.
    uint32_t component_type_;
    // DexCache of resolved constant pool entries (will be null for classes generated by the
    // runtime such as arrays and primitive classes).
    uint32_t dex_cache_;
    // The interface table (iftable_) contains pairs of a interface class and an array of the
    // interface methods. There is one pair per interface supported by this class.  That means one
    // pair for each interface we support directly, indirectly via superclass, or indirectly via a
    // superinterface.  This will be null if neither we nor our superclass implement any interfaces.
    //
    // Why we need this: given "class Foo implements Face", declare "Face faceObj = new Foo()".
    // Invoke faceObj.blah(), where "blah" is part of the Face interface.  We can't easily use a
    // single vtable.
    //
    // For every interface a concrete class implements, we create an array of the concrete vtable_
    // methods for the methods in the interface.
    uint32_t iftable_;
    // Descriptor for the class such as "java.lang.Class" or "[C". Lazily initialized by ComputeName
    uint32_t name_;
    // The superclass, or null if this is java.lang.Object or a primitive type.
    //
    // Note that interfaces have java.lang.Object as their
    // superclass. This doesn't match the expectations in JNI
    // GetSuperClass or java.lang.Class.getSuperClass() which need to
    // check for interfaces and return null.
    uint32_t super_class_;

    // If class verify fails, we must return same error on subsequent tries. We may store either
    // the class of the error, or an actual instance of Throwable here.
    uint32_t verify_error_;
    // Virtual method table (vtable), for use by "invoke-virtual".  The vtable from the superclass is
    // copied in, and virtual methods from our class either replace those from the super or are
    // appended. For abstract classes, methods may be created in the vtable that aren't in
    // virtual_ methods_ for miranda methods.
    uint32_t vtable_;
    // Access flags; low 16 bits are defined by VM spec.
    // Note: Shuffled back.
    uint32_t access_flags_;
    // Short cuts to dex_cache_ member for fast compiled code access.
    uint64_t dex_cache_strings_;

    // instance fields
    //
    // These describe the layout of the contents of an Object.
    // Note that only the fields directly declared by this class are
    // listed in ifields; fields declared by a superclass are listed in
    // the superclass's Class.ifields.
    //
    // ArtFields are allocated as a length prefixed ArtField array, and not an array of pointers to
    // ArtFields.
    uint64_t ifields_;
    // Pointer to an ArtMethod length-prefixed array. All the methods where this class is the place
    // where they are logically defined. This includes all private, static, final and virtual methods
    // as well as inherited default methods and miranda methods.
    //
    // The slice methods_ [0, virtual_methods_offset_) are the direct (static, private, init) methods
    // declared by this class.
    //
    // The slice methods_ [virtual_methods_offset_, copied_methods_offset_) are the virtual methods
    // declared by this class.
    //
    // The slice methods_ [copied_methods_offset_, |methods_|) are the methods that are copied from
    // interfaces such as miranda or default methods. These are copied for resolution purposes as this
    // class is where they are (logically) declared as far as the virtual dispatch is concerned.
    //
    // Note that this field is used by the native debugger as the unique identifier for the type.
    uint64_t methods_;

    // Static fields length-prefixed array.
    uint64_t sfields_;

    // Class flags to help speed up visiting object references.
    uint32_t class_flags_;

    // Total size of the Class instance; used when allocating storage on gc heap.
    // See also object_size_.
    uint32_t class_size_;
    // Tid used to check for recursive <clinit> invocation.
    pid_t clinit_thread_id_;
    // ClassDef index in dex file, -1 if no class definition such as an array.
    // TODO: really 16bits
    int32_t dex_class_def_idx_;
    // Type index in dex file.
    // TODO: really 16bits
    int32_t dex_type_idx_;
    // Number of instance fields that are object refs.
    uint32_t num_reference_instance_fields_;
    // Number of static fields that are object refs,
    uint32_t num_reference_static_fields_;
    // Total object size; used when allocating storage on gc heap.
    // (For interfaces and abstract classes this will be zero.)
    // See also class_size_.
    uint32_t object_size_;
    // The lower 16 bits contains a Primitive::Type value. The upper 16
    // bits contains the size shift of the primitive type.
    uint32_t primitive_type_;
    // Bitmap of offsets of ifields.
    uint32_t reference_instance_offsets_;
    // State of class initialization.
    uint32_t status_;
    // The offset of the first virtual method that is copied from an interface. This includes miranda,
    // default, and default-conflict methods. Having a hard limit of ((2 << 16) - 1) for methods
    // defined on a single class is well established in Java so we will use only uint16_t's here.
    uint16_t copied_methods_offset_;

    // The offset of the first declared virtual methods in the methods_ array.
    uint16_t virtual_methods_offset_;

};

class ArtMethod_API25 {
public:

    // Field order required by test "ValidateFieldOrderOfJavaCppUnionClasses".
    // The class we are a part of.
    uint32_t declaring_class_;
    // Access flags; low 16 bits are defined by spec.
    uint32_t access_flags_;
    /* Dex file fields. The defining dex file is available via declaring_class_->dex_cache_ */
    // Offset to the CodeItem.
    uint32_t dex_code_item_offset_;
    // Index into method_ids of the dex file associated with this method.
    uint32_t dex_method_index_;
    /* End of dex file fields. */
    // Entry within a dispatch table for this method. For static/direct methods the index is into
    // the declaringClass.directMethods, for virtual methods the vtable and for interface methods the
    // ifTable.
    uint16_t method_index_;

    // The hotness we measure for this method. Incremented by the interpreter. Not atomic, as we allow
    // missing increments: if the method is hot, we will see it eventually.
    uint16_t hotness_count_;

    // Fake padding field gets inserted here.
    // Must be the last fields in the method.
    // PACKED(4) is necessary for the correctness of
    // RoundUp(OFFSETOF_MEMBER(ArtMethod, ptr_sized_fields_), pointer_size).
    struct PtrSizedFields {
        // Short cuts to declaring_class_->dex_cache_ member for fast compiled code access.
        ArtMethod_API25 **dex_cache_resolved_methods_;

        // Short cuts to declaring_class_->dex_cache_ member for fast compiled code access.
        void *dex_cache_resolved_types_;

        // Pointer to JNI function registered to this method, or a function to resolve the JNI function,
        // or the profiling data for non-native methods, or an ImtConflictTable.
        void *entry_point_from_jni_;

        // Method dispatch from quick compiled code invokes this pointer which may cause bridging into
        // the interpreter.
        void *entry_point_from_quick_compiled_code_;
    } ptr_sized_fields_;
};


class ArtField_API25 {
public:
    uint32_t declaring_class_;
    uint32_t access_flags_;
    uint32_t field_dex_idx_;
    uint32_t offset_;
};


class Object_API26 {
public:
    // The number of vtable entries in java.lang.Object.
    uint32_t klass_;

    uint32_t monitor_;
};


class DexCache_API26 : public Object_API26 {
public:
    uint32_t location_;
    // Number of elements in the call_sites_ array. Note that this appears here
    // because of our packing logic for 32 bit fields.
    uint32_t num_resolved_call_sites_;

    uint64_t dex_file_;               // const DexFile*
    uint64_t resolved_call_sites_;    // GcRoot<CallSite>* array with num_resolved_call_sites_
    // elements.
    uint64_t resolved_fields_;        // std::atomic<FieldDexCachePair>*, array with
    // num_resolved_fields_ elements.
    uint64_t resolved_method_types_;  // std::atomic<MethodTypeDexCachePair>* array with
    // num_resolved_method_types_ elements.
    uint64_t resolved_methods_;       // ArtMethod*, array with num_resolved_methods_ elements.
    uint64_t resolved_types_;         // TypeDexCacheType*, array with num_resolved_types_ elements.
    uint64_t strings_;                // std::atomic<StringDexCachePair>*, array with num_strings_
    // elements.

    uint32_t num_resolved_fields_;        // Number of elements in the resolved_fields_ array.
    uint32_t num_resolved_method_types_;  // Number of elements in the resolved_method_types_ array.
    uint32_t num_resolved_methods_;       // Number of elements in the resolved_methods_ array.
    uint32_t num_resolved_types_;         // Number of elements in the resolved_types_ array.
    uint32_t num_strings_;                // Number of elements in the strings_ array.

};

class Class_API26 : public Object_API26 {
public:
    // Defining class loader, or null for the "bootstrap" system loader.
    uint32_t class_loader_;
    // For array classes, the component class object for instanceof/checkcast
    // (for String[][][], this will be String[][]). null for non-array classes.
    uint32_t component_type_;
    // DexCache of resolved constant pool entries (will be null for classes generated by the
    // runtime such as arrays and primitive classes).
    uint32_t dex_cache_;
    uint32_t ext_data_;
    uint32_t iftable_;

    // Descriptor for the class such as "java.lang.Class" or "[C". Lazily initialized by ComputeName
    uint32_t name_;

    // The superclass, or null if this is java.lang.Object or a primitive type.
    //
    // Note that interfaces have java.lang.Object as their
    // superclass. This doesn't match the expectations in JNI
    // GetSuperClass or java.lang.Class.getSuperClass() which need to
    // check for interfaces and return null.
    uint32_t super_class_;

    // Virtual method table (vtable), for use by "invoke-virtual".  The vtable from the superclass is
    // copied in, and virtual methods from our class either replace those from the super or are
    // appended. For abstract classes, methods may be created in the vtable that aren't in
    // virtual_ methods_ for miranda methods.
    uint32_t vtable_;
    uint64_t ifields_;
    uint64_t methods_;

    // Static fields length-prefixed array.
    uint64_t sfields_;

    // Access flags; low 16 bits are defined by VM spec.
    uint32_t access_flags_;

    // Class flags to help speed up visiting object references.
    uint32_t class_flags_;

    // Total size of the Class instance; used when allocating storage on gc heap.
    // See also object_size_.
    uint32_t class_size_;

    // Tid used to check for recursive <clinit> invocation.
    pid_t clinit_thread_id_;

    // ClassDef index in dex file, -1 if no class definition such as an array.
    // TODO: really 16bits
    int32_t dex_class_def_idx_;

    // Type index in dex file.
    // TODO: really 16bits
    int32_t dex_type_idx_;

    // Number of instance fields that are object refs.
    uint32_t num_reference_instance_fields_;

    // Number of static fields that are object refs,
    uint32_t num_reference_static_fields_;

    // Total object size; used when allocating storage on gc heap.
    // (For interfaces and abstract classes this will be zero.)
    // See also class_size_.
    uint32_t object_size_;

    // Aligned object size for allocation fast path. The value is max uint32_t if the object is
    // uninitialized or finalizable. Not currently used for variable sized objects.
    uint32_t object_size_alloc_fast_path_;

    // The lower 16 bits contains a Primitive::Type value. The upper 16
    // bits contains the size shift of the primitive type.
    uint32_t primitive_type_;

    // Bitmap of offsets of ifields.
    uint32_t reference_instance_offsets_;

    // State of class initialization.
    uint32_t status_;

    // The offset of the first virtual method that is copied from an interface. This includes miranda,
    // default, and default-conflict methods. Having a hard limit of ((2 << 16) - 1) for methods
    // defined on a single class is well established in Java so we will use only uint16_t's here.
    uint16_t copied_methods_offset_;

    // The offset of the first declared virtual methods in the methods_ array.
    uint16_t virtual_methods_offset_;

};

class ArtMethod_API26 {
public:
    // Field order required by test "ValidateFieldOrderOfJavaCppUnionClasses".
    // The class we are a part of.
    uint32_t declaring_class_;
    // Access flags; low 16 bits are defined by spec.
    uint32_t access_flags_;
    /* Dex file fields. The defining dex file is available via declaring_class_->dex_cache_ */
    // Offset to the CodeItem.
    uint32_t dex_code_item_offset_;
    // Index into method_ids of the dex file associated with this method.
    uint32_t dex_method_index_;
    /* End of dex file fields. */
    // Entry within a dispatch table for this method. For static/direct methods the index is into
    // the declaringClass.directMethods, for virtual methods the vtable and for interface methods the
    // ifTable.
    uint16_t method_index_;

    // The hotness we measure for this method. Incremented by the interpreter. Not atomic, as we allow
    // missing increments: if the method is hot, we will see it eventually.
    uint16_t hotness_count_;

    // Fake padding field gets inserted here.
    // Must be the last fields in the method.
    // PACKED(4) is necessary for the correctness of
    // RoundUp(OFFSETOF_MEMBER(ArtMethod, ptr_sized_fields_), pointer_size).
    struct PtrSizedFields {
        // Short cuts to declaring_class_->dex_cache_ member for fast compiled code access.
        ArtMethod_API26 **dex_cache_resolved_methods_;

        // Short cuts to declaring_class_->dex_cache_ member for fast compiled code access.
        void *dex_cache_resolved_types_;

        // Pointer to JNI function registered to this method, or a function to resolve the JNI function,
        // or the profiling data for non-native methods, or an ImtConflictTable.
        void *entry_point_from_jni_;

        // Method dispatch from quick compiled code invokes this pointer which may cause bridging into
        // the interpreter.
        void *entry_point_from_quick_compiled_code_;
    } ptr_sized_fields_;
};

class ArtField_API26 {
public:
    uint32_t declaring_class_;
    uint32_t access_flags_;
    uint32_t field_dex_idx_;
    uint32_t offset_;
};

class Object_API27 {
public:
    uint32_t klass_;
    uint32_t monitor_;
};

class DexCache_API27 : public Object_API27 {
public:
    uint32_t location_;
    // Number of elements in the call_sites_ array. Note that this appears here
    // because of our packing logic for 32 bit fields.
    uint32_t num_resolved_call_sites_;

    uint64_t dex_file_;               // const DexFile*
    uint64_t resolved_call_sites_;    // GcRoot<CallSite>* array with num_resolved_call_sites_
    // elements.
    uint64_t resolved_fields_;        // std::atomic<FieldDexCachePair>*, array with
    // num_resolved_fields_ elements.
    uint64_t resolved_method_types_;  // std::atomic<MethodTypeDexCachePair>* array with
    // num_resolved_method_types_ elements.
    uint64_t resolved_methods_;       // ArtMethod*, array with num_resolved_methods_ elements.
    uint64_t resolved_types_;         // TypeDexCacheType*, array with num_resolved_types_ elements.
    uint64_t strings_;                // std::atomic<StringDexCachePair>*, array with num_strings_
    // elements.

    uint32_t num_resolved_fields_;        // Number of elements in the resolved_fields_ array.
    uint32_t num_resolved_method_types_;  // Number of elements in the resolved_method_types_ array.
    uint32_t num_resolved_methods_;       // Number of elements in the resolved_methods_ array.
    uint32_t num_resolved_types_;         // Number of elements in the resolved_types_ array.
    uint32_t num_strings_;                // Number of elements in the strings_ array.

};

class Class_API27 : public Object_API27 {
public:
    uint32_t class_loader_;
    // For array classes, the component class object for instanceof/checkcast
    // (for String[][][], this will be String[][]). null for non-array classes.
    uint32_t component_type_;
    // DexCache of resolved constant pool entries (will be null for classes generated by the
    // runtime such as arrays and primitive classes).
    uint32_t dex_cache_;
    uint32_t ext_data_;
    uint32_t iftable_;

    // Descriptor for the class such as "java.lang.Class" or "[C". Lazily initialized by ComputeName
    uint32_t name_;

    // The superclass, or null if this is java.lang.Object or a primitive type.
    //
    // Note that interfaces have java.lang.Object as their
    // superclass. This doesn't match the expectations in JNI
    // GetSuperClass or java.lang.Class.getSuperClass() which need to
    // check for interfaces and return null.
    uint32_t super_class_;

    uint32_t vtable_;
    uint64_t ifields_;
    uint64_t methods_;

    // Static fields length-prefixed array.
    uint64_t sfields_;

    // Access flags; low 16 bits are defined by VM spec.
    uint32_t access_flags_;

    // Class flags to help speed up visiting object references.
    uint32_t class_flags_;

    // Total size of the Class instance; used when allocating storage on gc heap.
    // See also object_size_.
    uint32_t class_size_;

    // Tid used to check for recursive <clinit> invocation.
    pid_t clinit_thread_id_;

    // ClassDef index in dex file, -1 if no class definition such as an array.
    // TODO: really 16bits
    int32_t dex_class_def_idx_;

    // Type index in dex file.
    // TODO: really 16bits
    int32_t dex_type_idx_;

    // Number of instance fields that are object refs.
    uint32_t num_reference_instance_fields_;

    // Number of static fields that are object refs,
    uint32_t num_reference_static_fields_;

    // Total object size; used when allocating storage on gc heap.
    // (For interfaces and abstract classes this will be zero.)
    // See also class_size_.
    uint32_t object_size_;

    // Aligned object size for allocation fast path. The value is max uint32_t if the object is
    // uninitialized or finalizable. Not currently used for variable sized objects.
    uint32_t object_size_alloc_fast_path_;

    // The lower 16 bits contains a Primitive::Type value. The upper 16
    // bits contains the size shift of the primitive type.
    uint32_t primitive_type_;

    // Bitmap of offsets of ifields.
    uint32_t reference_instance_offsets_;

    // State of class initialization.
    uint32_t status_;

    // The offset of the first virtual method that is copied from an interface. This includes miranda,
    // default, and default-conflict methods. Having a hard limit of ((2 << 16) - 1) for methods
    // defined on a single class is well established in Java so we will use only uint16_t's here.
    uint16_t copied_methods_offset_;

    // The offset of the first declared virtual methods in the methods_ array.
    uint16_t virtual_methods_offset_;

};

class ArtMethod_API27 {
public:
    uint32_t declaring_class_;
    uint32_t access_flags_;
    uint32_t dex_code_item_offset_;
    uint32_t dex_method_index_;
    uint16_t method_index_;
    uint16_t hotness_count_;

    // Fake padding field gets inserted here.
    // Must be the last fields in the method.
    // PACKED(4) is necessary for the correctness of
    // RoundUp(OFFSETOF_MEMBER(ArtMethod, ptr_sized_fields_), pointer_size).
    struct PtrSizedFields {
        // Short cuts to declaring_class_->dex_cache_ member for fast compiled code access.
        ArtMethod_API27 **dex_cache_resolved_methods_;
        // Pointer to JNI function registered to this method, or a function to resolve the JNI function,
        // or the profiling data for non-native methods, or an ImtConflictTable.
        void *data;

        // Method dispatch from quick compiled code invokes this pointer which may cause bridging into
        // the interpreter.
        void *entry_point_from_quick_compiled_code_;
    } ptr_sized_fields_;
};

class ArtField_API27 {
public:
    uint32_t declaring_class_;
    uint32_t access_flags_;
    uint32_t field_dex_idx_;
    uint32_t offset_;
};

class Object_API28 {
public:
    uint32_t klass_;
    uint32_t monitor_;
};

class DexCache_API28 : public Object_API28 {
public:
    uint32_t location_;
    // Number of elements in the call_sites_ array. Note that this appears here
    // because of our packing logic for 32 bit fields.
    uint32_t num_resolved_call_sites_;

    uint64_t dex_file_;               // const DexFile*
    uint64_t resolved_call_sites_;    // GcRoot<CallSite>* array with num_resolved_call_sites_
    // elements.
    uint64_t resolved_fields_;        // std::atomic<FieldDexCachePair>*, array with
    // num_resolved_fields_ elements.
    uint64_t resolved_method_types_;  // std::atomic<MethodTypeDexCachePair>* array with
    // num_resolved_method_types_ elements.
    uint64_t resolved_methods_;       // ArtMethod*, array with num_resolved_methods_ elements.
    uint64_t resolved_types_;         // TypeDexCacheType*, array with num_resolved_types_ elements.
    uint64_t strings_;                // std::atomic<StringDexCachePair>*, array with num_strings_
    // elements.

    uint32_t num_resolved_fields_;        // Number of elements in the resolved_fields_ array.
    uint32_t num_resolved_method_types_;  // Number of elements in the resolved_method_types_ array.
    uint32_t num_resolved_methods_;       // Number of elements in the resolved_methods_ array.
    uint32_t num_resolved_types_;         // Number of elements in the resolved_types_ array.
    uint32_t num_strings_;                // Number of elements in the strings_ array.

};

class Class_API28 : public Object_API28 {
public:
    uint32_t class_loader_;
    // For array classes, the component class object for instanceof/checkcast
    // (for String[][][], this will be String[][]). null for non-array classes.
    uint32_t component_type_;
    // DexCache of resolved constant pool entries (will be null for classes generated by the
    // runtime such as arrays and primitive classes).
    uint32_t dex_cache_;
    uint32_t ext_data_;
    uint32_t iftable_;

    // Descriptor for the class such as "java.lang.Class" or "[C". Lazily initialized by ComputeName
    uint32_t name_;

    // The superclass, or null if this is java.lang.Object or a primitive type.
    //
    // Note that interfaces have java.lang.Object as their
    // superclass. This doesn't match the expectations in JNI
    // GetSuperClass or java.lang.Class.getSuperClass() which need to
    // check for interfaces and return null.
    uint32_t super_class_;

    uint32_t vtable_;
    uint64_t ifields_;
    uint64_t methods_;

    // Static fields length-prefixed array.
    uint64_t sfields_;

    // Access flags; low 16 bits are defined by VM spec.
    uint32_t access_flags_;

    // Class flags to help speed up visiting object references.
    uint32_t class_flags_;

    // Total size of the Class instance; used when allocating storage on gc heap.
    // See also object_size_.
    uint32_t class_size_;

    // Tid used to check for recursive <clinit> invocation.
    pid_t clinit_thread_id_;

    // ClassDef index in dex file, -1 if no class definition such as an array.
    // TODO: really 16bits
    int32_t dex_class_def_idx_;

    // Type index in dex file.
    // TODO: really 16bits
    int32_t dex_type_idx_;

    // Number of instance fields that are object refs.
    uint32_t num_reference_instance_fields_;

    // Number of static fields that are object refs,
    uint32_t num_reference_static_fields_;

    // Total object size; used when allocating storage on gc heap.
    // (For interfaces and abstract classes this will be zero.)
    // See also class_size_.
    uint32_t object_size_;

    // Aligned object size for allocation fast path. The value is max uint32_t if the object is
    // uninitialized or finalizable. Not currently used for variable sized objects.
    uint32_t object_size_alloc_fast_path_;

    // The lower 16 bits contains a Primitive::Type value. The upper 16
    // bits contains the size shift of the primitive type.
    uint32_t primitive_type_;

    // Bitmap of offsets of ifields.
    uint32_t reference_instance_offsets_;

    // State of class initialization.
    uint32_t status_;

    // The offset of the first virtual method that is copied from an interface. This includes miranda,
    // default, and default-conflict methods. Having a hard limit of ((2 << 16) - 1) for methods
    // defined on a single class is well established in Java so we will use only uint16_t's here.
    uint16_t copied_methods_offset_;

    // The offset of the first declared virtual methods in the methods_ array.
    uint16_t virtual_methods_offset_;

};

class ArtMethod_API28 {
public:
    uint32_t declaring_class_;
    uint32_t access_flags_;
    uint32_t dex_code_item_offset_;
    uint32_t dex_method_index_;
    uint16_t method_index_;
    uint16_t hotness_count_;

    // Fake padding field gets inserted here.
    // Must be the last fields in the method.
    // PACKED(4) is necessary for the correctness of
    // RoundUp(OFFSETOF_MEMBER(ArtMethod, ptr_sized_fields_), pointer_size).
    struct PtrSizedFields {
        // Short cuts to declaring_class_->dex_cache_ member for fast compiled code access.
        ArtMethod_API27 **dex_cache_resolved_methods_;
        // Pointer to JNI function registered to this method, or a function to resolve the JNI function,
        // or the profiling data for non-native methods, or an ImtConflictTable.
        void *data;

        // Method dispatch from quick compiled code invokes this pointer which may cause bridging into
        // the interpreter.
        void *entry_point_from_quick_compiled_code_;
    } ptr_sized_fields_;
};

class ArtField_API28 {
public:
    uint32_t declaring_class_;
    uint32_t access_flags_;
    uint32_t field_dex_idx_;
    uint32_t offset_;
};


//====================
/* return the DexMapList of the file, if any */
DEX_INLINE const DexMapList *dexGetMap(const DexFile *pDexFile) {
    u4 mapOff = pDexFile->pHeader->mapOff;

    if (mapOff == 0) {
        return NULL;
    } else {
        return (const DexMapList *) (pDexFile->baseAddr + mapOff);
    }
}

/* return the const char* string data referred to by the given string_id */
DEX_INLINE const char *dexGetStringData(const DexFile *pDexFile,
                                        const DexStringId *pStringId) {
    const u1 *ptr = pDexFile->baseAddr + pStringId->stringDataOff;

    // Skip the uleb128 length.
    while (*(ptr++) > 0x7f) /* empty */;

    return (const char *) ptr;
}
/* return the StringId with the specified index */
DEX_INLINE const DexStringId *dexGetStringId(const DexFile *pDexFile, u4 idx) {
    assert(idx < pDexFile->pHeader->stringIdsSize);
    return &pDexFile->pStringIds[idx];
}
/* return the UTF-8 encoded string with the specified string_id index */
DEX_INLINE const char *dexStringById(const DexFile *pDexFile, u4 idx) {
    const DexStringId *pStringId = dexGetStringId(pDexFile, idx);
    return dexGetStringData(pDexFile, pStringId);
}

/* Return the UTF-8 encoded string with the specified string_id index,
* also filling in the UTF-16 size (number of 16-bit code points).*/
const char *dexStringAndSizeById(const DexFile *pDexFile, u4 idx,
                                 u4 *utf16Size);

/* return the TypeId with the specified index */
DEX_INLINE const DexTypeId *dexGetTypeId(const DexFile *pDexFile, u4 idx) {
    assert(idx < pDexFile->pHeader->typeIdsSize);
    return &pDexFile->pTypeIds[idx];
}

/*
* Get the descriptor string associated with a given type index.
* The caller should not free() the returned string.
*/
DEX_INLINE const char *dexStringByTypeIdx(const DexFile *pDexFile, u4 idx) {
    const DexTypeId *typeId = dexGetTypeId(pDexFile, idx);
    return dexStringById(pDexFile, typeId->descriptorIdx);
}

/* return the MethodId with the specified index */
DEX_INLINE const DexMethodId *dexGetMethodId(const DexFile *pDexFile, u4 idx) {
    assert(idx < pDexFile->pHeader->methodIdsSize);
    return &pDexFile->pMethodIds[idx];
}

/* return the FieldId with the specified index */
DEX_INLINE const DexFieldId *dexGetFieldId(const DexFile *pDexFile, u4 idx) {
    assert(idx < pDexFile->pHeader->fieldIdsSize);
    return &pDexFile->pFieldIds[idx];
}

/* return the ProtoId with the specified index */
DEX_INLINE const DexProtoId *dexGetProtoId(const DexFile *pDexFile, u4 idx) {
    assert(idx < pDexFile->pHeader->protoIdsSize);
    return &pDexFile->pProtoIds[idx];
}

/*
* Get the parameter list from a ProtoId. The returns NULL if the ProtoId
* does not have a parameter list.
*/
DEX_INLINE const DexTypeList *dexGetProtoParameters(
        const DexFile *pDexFile, const DexProtoId *pProtoId) {
    if (pProtoId->parametersOff == 0) {
        return NULL;
    }
    return reinterpret_cast<const DexTypeList *>(pDexFile->baseAddr + pProtoId->parametersOff);
}

/* return the ClassDef with the specified index */
DEX_INLINE const DexClassDef *dexGetClassDef(const DexFile *pDexFile, u4 idx) {
    assert(idx < pDexFile->pHeader->classDefsSize);
    return &pDexFile->pClassDefs[idx];
}

/* given a ClassDef pointer, recover its index */
DEX_INLINE u4 dexGetIndexForClassDef(const DexFile *pDexFile,
                                     const DexClassDef *pClassDef) {
    assert(pClassDef >= pDexFile->pClassDefs &&
           pClassDef < pDexFile->pClassDefs + pDexFile->pHeader->classDefsSize);
    return pClassDef - pDexFile->pClassDefs;
}

/* get the interface list for a DexClass */
DEX_INLINE const DexTypeList *dexGetInterfacesList(const DexFile *pDexFile,
                                                   const DexClassDef *pClassDef) {
    if (pClassDef->interfacesOff == 0)
        return nullptr;
    return reinterpret_cast<const DexTypeList *>(pDexFile->baseAddr + pClassDef->interfacesOff);
}
/* return the Nth entry in a DexTypeList. */
DEX_INLINE const DexTypeItem *dexGetTypeItem(const DexTypeList *pList,
                                             u4 idx) {
    assert(idx < pList->size);
    return &pList->list[idx];
}
/* return the type_idx for the Nth entry in a TypeList */
DEX_INLINE u4 dexTypeListGetIdx(const DexTypeList *pList, u4 idx) {
    const DexTypeItem *pItem = dexGetTypeItem(pList, idx);
    return pItem->typeIdx;
}

/* get the static values list for a DexClass */
DEX_INLINE const DexEncodedArray *dexGetStaticValuesList(
        const DexFile *pDexFile, const DexClassDef *pClassDef) {
    if (pClassDef->staticValuesOff == 0)
        return NULL;
    return (const DexEncodedArray *)
            (pDexFile->baseAddr + pClassDef->staticValuesOff);
}

DEX_INLINE const DexAnnotationsDirectoryItem *dexGetAnnotationsDirectoryItem(
        const DexFile *pDexFile, const DexClassDef *pClassDef) {
    if (pClassDef->annotationsOff == 0)
        return NULL;
    return (const DexAnnotationsDirectoryItem *)
            (pDexFile->baseAddr + pClassDef->annotationsOff);
}

DEX_INLINE const char *dexGetSourceFile(
        const DexFile *pDexFile, const DexClassDef *pClassDef) {
    if (pClassDef->sourceFileIdx == 0xffffffff)
        return NULL;
    return dexStringById(pDexFile, pClassDef->sourceFileIdx);
}

/* get the size, in bytes, of a DexCode */






size_t dexGetDexCodeSize(const DexCode *pCode);
/* get a pointer to the start of the debugging data */
DEX_INLINE const u1 *dexGetDebugInfoStream(const DexFile *pDexFile,
                                           const DexCode *pCode) {
    if (pCode->debugInfoOff == 0) {
        return NULL;
    } else {
        return pDexFile->baseAddr + pCode->debugInfoOff;
    }
}

/* DexClassDef convenience - get class descriptor */
DEX_INLINE const char *dexGetClassDescriptor(const DexFile *pDexFile,
                                             const DexClassDef *pClassDef) {
    return dexStringByTypeIdx(pDexFile, pClassDef->classIdx);
}

/* DexClassDef convenience - get superclass descriptor */
DEX_INLINE const char *dexGetSuperClassDescriptor(const DexFile *pDexFile,
                                                  const DexClassDef *pClassDef) {
    if (pClassDef->superclassIdx == 0)
        return NULL;
    return dexStringByTypeIdx(pDexFile, pClassDef->superclassIdx);
}

/* DexClassDef convenience - get class_data_item pointer */
DEX_INLINE const u1 *dexGetClassData(const DexFile *pDexFile,
                                     const DexClassDef *pClassDef) {
    if (pClassDef->classDataOff == 0)
        return NULL;
    return (const u1 *) (pDexFile->baseAddr + pClassDef->classDataOff);
}

/* Get an annotation set at a particular offset. */
DEX_INLINE const DexAnnotationSetItem *dexGetAnnotationSetItem(
        const DexFile *pDexFile, u4 offset) {
    return (const DexAnnotationSetItem *) (pDexFile->baseAddr + offset);
}
/* get the class' annotation set */
DEX_INLINE const DexAnnotationSetItem *dexGetClassAnnotationSet(
        const DexFile *pDexFile, const DexAnnotationsDirectoryItem *pAnnoDir) {
    if (pAnnoDir->classAnnotationsOff == 0)
        return NULL;
    return dexGetAnnotationSetItem(pDexFile, pAnnoDir->classAnnotationsOff);
}

/* get the class' field annotation list */
DEX_INLINE const DexFieldAnnotationsItem *dexGetFieldAnnotations(
        const DexFile *pDexFile, const DexAnnotationsDirectoryItem *pAnnoDir) {
    if (pAnnoDir->fieldsSize == 0)
        return NULL;

    // Skip past the header to the start of the field annotations.
    return (const DexFieldAnnotationsItem *) &pAnnoDir[1];
}

/* get field annotation list size */
DEX_INLINE int dexGetFieldAnnotationsSize(const DexFile *pDexFile,
                                          const DexAnnotationsDirectoryItem *pAnnoDir) {
    return pAnnoDir->fieldsSize;
}

/* return a pointer to the field's annotation set */
DEX_INLINE const DexAnnotationSetItem *dexGetFieldAnnotationSetItem(
        const DexFile *pDexFile, const DexFieldAnnotationsItem *pItem) {
    return dexGetAnnotationSetItem(pDexFile, pItem->annotationsOff);
}

/* get the class' method annotation list */
DEX_INLINE const DexMethodAnnotationsItem *dexGetMethodAnnotations(
        const DexFile *pDexFile, const DexAnnotationsDirectoryItem *pAnnoDir) {
    if (pAnnoDir->methodsSize == 0)
        return NULL;

    /*
    * Skip past the header and field annotations to the start of the
    * method annotations.
    */
    const u1 *addr = (const u1 *) &pAnnoDir[1];
    addr += pAnnoDir->fieldsSize * sizeof(DexFieldAnnotationsItem);
    return (const DexMethodAnnotationsItem *) addr;
}

/* get method annotation list size */
DEX_INLINE int dexGetMethodAnnotationsSize(const DexFile *pDexFile,
                                           const DexAnnotationsDirectoryItem *pAnnoDir) {
    return pAnnoDir->methodsSize;
}

/* return a pointer to the method's annotation set */
DEX_INLINE const DexAnnotationSetItem *dexGetMethodAnnotationSetItem(
        const DexFile *pDexFile, const DexMethodAnnotationsItem *pItem) {
    return dexGetAnnotationSetItem(pDexFile, pItem->annotationsOff);
}

/* get the class' parameter annotation list */
DEX_INLINE const DexParameterAnnotationsItem *dexGetParameterAnnotations(
        const DexFile *pDexFile, const DexAnnotationsDirectoryItem *pAnnoDir) {
    if (pAnnoDir->parametersSize == 0)
        return NULL;

    /*
    * Skip past the header, field annotations, and method annotations
    * to the start of the parameter annotations.
    */
    const u1 *addr = (const u1 *) &pAnnoDir[1];
    addr += pAnnoDir->fieldsSize * sizeof(DexFieldAnnotationsItem);
    addr += pAnnoDir->methodsSize * sizeof(DexMethodAnnotationsItem);
    return (const DexParameterAnnotationsItem *) addr;
}

/* get method annotation list size */
DEX_INLINE int dexGetParameterAnnotationsSize(const DexFile *pDexFile,
                                              const DexAnnotationsDirectoryItem *pAnnoDir) {
    return pAnnoDir->parametersSize;
}

/* return the parameter annotation ref list */
DEX_INLINE const DexAnnotationSetRefList *dexGetParameterAnnotationSetRefList(
        const DexFile *pDexFile, const DexParameterAnnotationsItem *pItem) {
    return (const DexAnnotationSetRefList *)
            (pDexFile->baseAddr + pItem->annotationsOff);
}

/* get method annotation list size */
DEX_INLINE int dexGetParameterAnnotationSetRefSize(const DexFile *pDexFile,
                                                   const DexParameterAnnotationsItem *pItem) {
    if (pItem->annotationsOff == 0)
        return 0;
    return dexGetParameterAnnotationSetRefList(pDexFile, pItem)->size;
}

/* return the Nth entry from an annotation set ref list */

DEX_INLINE const DexAnnotationSetRefItem *dexGetParameterAnnotationSetRef(
        const DexAnnotationSetRefList *pList, u4 idx) {
    assert(idx < pList->size);
    return &pList->list[idx];
}

/* given a DexAnnotationSetRefItem, return the DexAnnotationSetItem */
DEX_INLINE const DexAnnotationSetItem *dexGetSetRefItemItem(
        const DexFile *pDexFile, const DexAnnotationSetRefItem *pItem) {
    return dexGetAnnotationSetItem(pDexFile, pItem->annotationsOff);
}

/* return the Nth annotation offset from a DexAnnotationSetItem */
DEX_INLINE u4 dexGetAnnotationOff(
        const DexAnnotationSetItem *pAnnoSet, u4 idx) {
    assert(idx < pAnnoSet->size);
    return pAnnoSet->entries[idx];
}

/* return the Nth annotation item from a DexAnnotationSetItem */
DEX_INLINE const DexAnnotationItem *dexGetAnnotationItem(
        const DexFile *pDexFile, const DexAnnotationSetItem *pAnnoSet, u4 idx) {
    return (const DexAnnotationItem *)
            (pDexFile->baseAddr + dexGetAnnotationOff(pAnnoSet, idx));
}

DEX_INLINE void dexFileSetupBasicPointers(DexFile *pDexFile, u1 *data) {
    DexHeader *pHeader = reinterpret_cast<DexHeader *>(data);

    pDexFile->baseAddr = data;
    pDexFile->pHeader = pHeader;
    pDexFile->pStringIds = reinterpret_cast<const DexStringId *>(data + pHeader->stringIdsOff);
    pDexFile->pTypeIds = reinterpret_cast<const DexTypeId *>(data + pHeader->typeIdsOff);
    pDexFile->pFieldIds = reinterpret_cast<const DexFieldId *>(data + pHeader->fieldIdsOff);
    pDexFile->pMethodIds = reinterpret_cast<const DexMethodId *>(data + pHeader->methodIdsOff);
    pDexFile->pProtoIds = reinterpret_cast<const DexProtoId *>(data + pHeader->protoIdsOff);
    pDexFile->pClassDefs = reinterpret_cast<const DexClassDef *>(data + pHeader->classDefsOff);
    pDexFile->pLinkData = reinterpret_cast<const DexLink *>(data + pHeader->linkOff);
}


/* basic info about a field or method */
struct FieldMethodInfo {
    const char *classDescriptor;
    const char *name;
    const char *signature;
};

/*
 * Set the given DexProto to refer to the prototype of the given MethodId.
 */
DEX_INLINE void dexProtoSetFromMethodId(DexProto *pProto,
                                        const DexFile *pDexFile, const DexMethodId *pMethodId) {
    pProto->dexFile = pDexFile;
    pProto->protoIdx = pMethodId->protoIdx;
}

/*
 * Single-thread single-string cache. This structure holds a pointer to
 * a string which is semi-automatically manipulated by some of the
 * method prototype functions. Functions which use in this struct
 * generally return a string that is valid until the next
 * time the same DexStringCache is used.
 */
struct DexStringCache {
    char *value;          /* the latest value */
    size_t allocatedSize; /* size of the allocated buffer, if allocated */
    char buffer[120];     /* buffer used to hold small-enough results */
};

/*
 * Initialize the given DexStringCache. Use this function before passing
 * one into any other function.
 */
DEX_INLINE void dexStringCacheInit(DexStringCache *pCache) {
    pCache->value = pCache->buffer;
    pCache->allocatedSize = 0;
    pCache->buffer[0] = '\0';
}


/*
 * Abandon the given DexStringCache, and return a writable copy of the
 * given value (reusing the string cache's allocation if possible).
 * The return value must be free()d by the caller. Use this instead of
 * dexStringCacheRelease() if you want the buffer to survive past the
 * scope of the DexStringCache.
 */
DEX_INLINE char *dexStringCacheAbandon(DexStringCache *pCache, const char *value) {
    if ((value == pCache->value) && (pCache->allocatedSize != 0)) {
        char *result = pCache->value;
        pCache->allocatedSize = 0;
        pCache->value = pCache->buffer;
        return result;
    } else {
        return strdup(value);
    }
}


/*
 * Make sure that the given cache can hold a string of the given length,
 * including the final '\0' byte.
 */
DEX_INLINE void dexStringCacheAlloc(DexStringCache *pCache, size_t length) {
    if (pCache->allocatedSize != 0) {
        if (pCache->allocatedSize >= length) {
            return;
        }
        free((void *) pCache->value);
    }

    if (length <= sizeof(pCache->buffer)) {
        pCache->value = pCache->buffer;
        pCache->allocatedSize = 0;
    } else {
        pCache->value = (char *) malloc(length);
        pCache->allocatedSize = length;
    }
}

/*
 * Return the DexProtoId from the given DexProto. The DexProto must
 * actually refer to a DexProtoId.
 */
static inline const DexProtoId *getProtoId(const DexProto *pProto) {
    return dexGetProtoId(pProto->dexFile, pProto->protoIdx);
}
/* (documented in header file) */
DEX_INLINE const char *dexProtoGetMethodDescriptor(const DexProto *pProto,
                                                   DexStringCache *pCache) {
    const DexFile *dexFile = pProto->dexFile;
    const DexProtoId *protoId = getProtoId(pProto);
    const DexTypeList *typeList = dexGetProtoParameters(dexFile, protoId);
    size_t length = 3; // parens and terminating '\0'
    u4 paramCount = (typeList == NULL) ? 0 : typeList->size;
    u4 i;

    for (i = 0; i < paramCount; i++) {
        u4 idx = dexTypeListGetIdx(typeList, i);
        length += strlen(dexStringByTypeIdx(dexFile, idx));
    }

    length += strlen(dexStringByTypeIdx(dexFile, protoId->returnTypeIdx));

    dexStringCacheAlloc(pCache, length);

    char *at = (char *) pCache->value;
    *(at++) = '(';

    for (i = 0; i < paramCount; i++) {
        u4 idx = dexTypeListGetIdx(typeList, i);
        const char *desc = dexStringByTypeIdx(dexFile, idx);
        strcpy(at, desc);
        at += strlen(desc);
    }

    *(at++) = ')';

    strcpy(at, dexStringByTypeIdx(dexFile, protoId->returnTypeIdx));
    return pCache->value;
}
/* (documented in header file) */
DEX_INLINE char *dexProtoCopyMethodDescriptor(const DexProto *pProto) {
    DexStringCache cache;

    dexStringCacheInit(&cache);
    return dexStringCacheAbandon(&cache,
                                 dexProtoGetMethodDescriptor(pProto, &cache));
}

/*
 * Get a copy of the utf-8 encoded method descriptor string from the
 * proto of a MethodId. The returned pointer must be free()ed by the
 * caller.
 */
DEX_INLINE char *dexCopyDescriptorFromMethodId(const DexFile *pDexFile,
                                               const DexMethodId *pMethodId) {
    DexProto proto;

    dexProtoSetFromMethodId(&proto, pDexFile, pMethodId);
    return dexProtoCopyMethodDescriptor(&proto);
}

/*
 * Get information about a method.
 */
inline bool getMethodInfo(DexFile *pDexFile, u4 methodIdx, FieldMethodInfo *pMethInfo) {
    const DexMethodId *pMethodId;

    if (methodIdx >= pDexFile->pHeader->methodIdsSize)
        return false;

    pMethodId = dexGetMethodId(pDexFile, methodIdx);
    pMethInfo->name = dexStringById(pDexFile, pMethodId->nameIdx);
    pMethInfo->signature = dexCopyDescriptorFromMethodId(pDexFile, pMethodId);

    pMethInfo->classDescriptor =
            dexStringByTypeIdx(pDexFile, pMethodId->classIdx);
    return true;
}


/*
 * Get information about a field.
 */
inline bool getFieldInfo(DexFile *pDexFile, u4 fieldIdx, FieldMethodInfo *pFieldInfo) {
    const DexFieldId *pFieldId;

    if (fieldIdx >= pDexFile->pHeader->fieldIdsSize)
        return false;

    pFieldId = dexGetFieldId(pDexFile, fieldIdx);
    pFieldInfo->name = dexStringById(pDexFile, pFieldId->nameIdx);
    pFieldInfo->signature = dexStringByTypeIdx(pDexFile, pFieldId->typeIdx);
    pFieldInfo->classDescriptor =
            dexStringByTypeIdx(pDexFile, pFieldId->classIdx);
    return true;
}

#endif

