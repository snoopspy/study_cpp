----- string test -----
Malloc::acquire 0x602120 size=26
Malloc::release 0x602120
----- string pointer test -----
Malloc::acquire 0x60213a size=8
Malloc::acquire 0x602142 size=26
Malloc::release 0x602142
Malloc::release 0x60213a
----- MyNewString test -----
Malloc::acquire 0x60215c size=26
Malloc::release 0x60215c
----- MyNewString pointer test -----
MyNewString::new size=8
Malloc::acquire 0x602176 size=8
Malloc::acquire 0x60217e size=26
Malloc::release 0x60217e
MyNewString::delete ptr=0x602176
Malloc::release 0x602176
----- MyAllocString test -----
Malloc::acquire 0x602198 size=26
Malloc::release 0x602198
----- MyAllocString pointer test -----
Malloc::acquire 0x6021b2 size=8
Malloc::acquire 0x6021ba size=26
Malloc::release 0x6021ba
Malloc::release 0x6021b2
