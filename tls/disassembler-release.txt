        8 [1]	int main() {
0x4009a0                   48 83 ec 08              sub    $0x8,%rsp
        12 [1]	    n = s.b_;
0x4009a4  <+0x0004>        48 8d 05 e5 16 20 00     lea    0x2016e5(%rip),%rax        # 0x602090 <s>
        13 [1]	    write(n);
0x4009ab  <+0x000b>        8b 78 04                 mov    0x4(%rax),%edi
0x4009ae  <+0x000e>        e8 3d 03 00 00           callq  0x400cf0 <write(int)>
        15 [1]	    n = c.b_;
0x4009b3  <+0x0013>        48 8d 05 06 17 20 00     lea    0x201706(%rip),%rax        # 0x6020c0 <c>
        16 [1]	    write(n);
0x4009ba  <+0x001a>        8b 78 04                 mov    0x4(%rax),%edi
0x4009bd  <+0x001d>        e8 2e 03 00 00           callq  0x400cf0 <write(int)>
        18 [1]	    n = ts.b_;
0x4009c2  <+0x0022>        48 c7 c0 bc ff ff ff     mov    $0xffffffffffffffbc,%rax
        19 [1]	    write(n);
0x4009c9  <+0x0029>        64 8b 78 04              mov    %fs:0x4(%rax),%edi
0x4009cd  <+0x002d>        e8 1e 03 00 00           callq  0x400cf0 <write(int)>
        48 [1]	}
0x4009d2  <+0x0032>        48 83 3d 0e 16 20 00 00  cmpq   $0x0,0x20160e(%rip)        # 0x601fe8
0x4009da  <+0x003a>        74 05                    je     0x4009e1 <main()+65>
0x4009dc  <+0x003c>        e8 4f ff ff ff           callq  0x400930 <_ZTH3tls@plt>
        21 [1]	    n = tls.b_;
0x4009e1  <+0x0041>        48 c7 c0 b0 ff ff ff     mov    $0xffffffffffffffb0,%rax
        22 [1]	    write(n);
0x4009e8  <+0x0048>        64 8b 78 04              mov    %fs:0x4(%rax),%edi
0x4009ec  <+0x004c>        e8 ff 02 00 00           callq  0x400cf0 <write(int)>
        48 [2]	}
0x4009f1  <+0x0051>        e8 ba 02 00 00           callq  0x400cb0 <__tls_init()>
        24 [1]	    n = tlc.b_;
0x4009f6  <+0x0056>        48 c7 c0 f0 ff ff ff     mov    $0xfffffffffffffff0,%rax
        25 [1]	    write(n);
0x4009fd  <+0x005d>        64 8b 78 04              mov    %fs:0x4(%rax),%edi
0x400a01  <+0x0061>        e8 ea 02 00 00           callq  0x400cf0 <write(int)>
        28 [1]	  initPointer();
0x400a06  <+0x0066>        e8 b5 01 00 00           callq  0x400bc0 <initPointer()>
        30 [1]	    n = ps->b_;
0x400a0b  <+0x006b>        48 8d 05 a6 16 20 00     lea    0x2016a6(%rip),%rax        # 0x6020b8 <ps>
0x400a12  <+0x0072>        48 8b 00                 mov    (%rax),%rax
        31 [1]	    write(n);
0x400a15  <+0x0075>        8b 78 04                 mov    0x4(%rax),%edi
0x400a18  <+0x0078>        e8 d3 02 00 00           callq  0x400cf0 <write(int)>
        33 [1]	    n = pc->b_;
0x400a1d  <+0x007d>        48 8d 05 8c 16 20 00     lea    0x20168c(%rip),%rax        # 0x6020b0 <pc>
0x400a24  <+0x0084>        48 8b 00                 mov    (%rax),%rax
        34 [1]	    write(n);
0x400a27  <+0x0087>        8b 78 04                 mov    0x4(%rax),%edi
0x400a2a  <+0x008a>        e8 c1 02 00 00           callq  0x400cf0 <write(int)>
        36 [1]	    n = pts->b_;
0x400a2f  <+0x008f>        48 c7 c0 e8 ff ff ff     mov    $0xffffffffffffffe8,%rax
0x400a36  <+0x0096>        64 48 8b 00              mov    %fs:(%rax),%rax
        37 [1]	    write(n);
0x400a3a  <+0x009a>        8b 78 04                 mov    0x4(%rax),%edi
0x400a3d  <+0x009d>        e8 ae 02 00 00           callq  0x400cf0 <write(int)>
        39 [1]	    n = ptc->b_;
0x400a42  <+0x00a2>        48 c7 c0 e0 ff ff ff     mov    $0xffffffffffffffe0,%rax
0x400a49  <+0x00a9>        64 48 8b 00              mov    %fs:(%rax),%rax
        40 [1]	    write(n);
0x400a4d  <+0x00ad>        8b 78 04                 mov    0x4(%rax),%edi
0x400a50  <+0x00b0>        e8 9b 02 00 00           callq  0x400cf0 <write(int)>
        48 [3]	}
0x400a55  <+0x00b5>        48 83 3d 7b 15 20 00 00  cmpq   $0x0,0x20157b(%rip)        # 0x601fd8
0x400a5d  <+0x00bd>        74 05                    je     0x400a64 <main()+196>
0x400a5f  <+0x00bf>        e8 7c fe ff ff           callq  0x4008e0 <_ZTH4ptls@plt>
        42 [1]	    n = ptls->b_;
0x400a64  <+0x00c4>        48 c7 c0 d8 ff ff ff     mov    $0xffffffffffffffd8,%rax
0x400a6b  <+0x00cb>        64 48 8b 00              mov    %fs:(%rax),%rax
        43 [1]	    write(n);
0x400a6f  <+0x00cf>        8b 78 04                 mov    0x4(%rax),%edi
0x400a72  <+0x00d2>        e8 79 02 00 00           callq  0x400cf0 <write(int)>
        48 [4]	}
0x400a77  <+0x00d7>        48 83 3d 79 15 20 00 00  cmpq   $0x0,0x201579(%rip)        # 0x601ff8
0x400a7f  <+0x00df>        74 05                    je     0x400a86 <main()+230>
0x400a81  <+0x00e1>        e8 ea fe ff ff           callq  0x400970 <_ZTH4ptlc@plt>
        45 [1]	    n = ptlc->b_;
0x400a86  <+0x00e6>        48 c7 c0 d0 ff ff ff     mov    $0xffffffffffffffd0,%rax
0x400a8d  <+0x00ed>        64 48 8b 00              mov    %fs:(%rax),%rax
        46 [1]	    write(n);
0x400a91  <+0x00f1>        8b 78 04                 mov    0x4(%rax),%edi
0x400a94  <+0x00f4>        e8 57 02 00 00           callq  0x400cf0 <write(int)>
        48 [5]	}
0x400a99  <+0x00f9>        31 c0                    xor    %eax,%eax
0x400a9b  <+0x00fb>        48 83 c4 08              add    $0x8,%rsp
0x400a9f  <+0x00ff>        c3                       retq
