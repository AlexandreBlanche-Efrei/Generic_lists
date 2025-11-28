# Simplified version

To define generic structures for a given type ``type`` :

- Copy-paste the files ``struct.h`` and ``struct.c``, and rename them with your structure name, for instance ``struct_float.h`` and ``struct_float.c``.

- Modify the macros ``FILE_H`` for a new unique macro name in your ``.h`` file.

- Modify the macros ``T`` with your type, ``STRUCT_NAME`` with your struct type name, ``GET_FUNCTION`` with the name of the getter function, ``SET_FUNCTION`` with the name of the setter function.

- Modify the ``#include "struct.h"`` in your ``.c`` file.

You are ready to go! You can now include your ``.h`` file wherever you want, and use the structured type you just defined.
