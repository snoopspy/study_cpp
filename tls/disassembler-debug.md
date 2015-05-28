        8 [1]	int main() {
0x400b89                   55                    push   %rbp
0x400b8a  <+0x0001>        48 89 e5              mov    %rsp,%rbp
0x400b8d  <+0x0004>        48 83 ec 10           sub    $0x10,%rsp
        12 [1]	    n = s.b_;
0x400b91  <+0x0008>        48 8d 05 e0 14 20 00  lea    0x2014e0(%rip),%rax        # 0x602078 <s>
0x400b98  <+0x000f>        8b 40 04              mov    0x4(%rax),%eax
0x400b9b  <+0x0012>        89 45 fc              mov    %eax,-0x4(%rbp)
        13 [1]	    write(n);
0x400b9e  <+0x0015>        8b 45 fc              mov    -0x4(%rbp),%eax
0x400ba1  <+0x0018>        89 c7                 mov    %eax,%edi
0x400ba3  <+0x001a>        e8 ae ff ff ff        callq  0x400b56 <write(int)>
        15 [1]	    n = c.b_;
0x400ba8  <+0x001f>        48 8d 05 f1 14 20 00  lea    0x2014f1(%rip),%rax        # 0x6020a0 <c>
0x400baf  <+0x0026>        8b 40 04              mov    0x4(%rax),%eax
0x400bb2  <+0x0029>        89 45 fc              mov    %eax,-0x4(%rbp)
        16 [1]	    write(n);
0x400bb5  <+0x002c>        8b 45 fc              mov    -0x4(%rbp),%eax
0x400bb8  <+0x002f>        89 c7                 mov    %eax,%edi
0x400bba  <+0x0031>        e8 97 ff ff ff        callq  0x400b56 <write(int)>
        18 [1]	    n = ts.b_;
0x400bbf  <+0x0036>        48 c7 c0 b0 ff ff ff  mov    $0xffffffffffffffb0,%rax
0x400bc6  <+0x003d>        64 8b 40 04           mov    %fs:0x4(%rax),%eax
0x400bca  <+0x0041>        89 45 fc              mov    %eax,-0x4(%rbp)
        19 [1]	    write(n);
0x400bcd  <+0x0044>        8b 45 fc              mov    -0x4(%rbp),%eax
0x400bd0  <+0x0047>        89 c7                 mov    %eax,%edi
0x400bd2  <+0x0049>        e8 7f ff ff ff        callq  0x400b56 <write(int)>
        21 [1]	    n = tls.b_;
0x400bd7  <+0x004e>        e8 28 01 00 00        callq  0x400d04 <_ZTW3tls>
0x400bdc  <+0x0053>        8b 40 04              mov    0x4(%rax),%eax
0x400bdf  <+0x0056>        89 45 fc              mov    %eax,-0x4(%rbp)
        22 [1]	    write(n);
0x400be2  <+0x0059>        8b 45 fc              mov    -0x4(%rbp),%eax
0x400be5  <+0x005c>        89 c7                 mov    %eax,%edi
0x400be7  <+0x005e>        e8 6a ff ff ff        callq  0x400b56 <write(int)>
        24 [1]	    n = tlc.b_;
0x400bec  <+0x0063>        e8 3d 01 00 00        callq  0x400d2e <_ZTW3tlc>
0x400bf1  <+0x0068>        8b 40 04              mov    0x4(%rax),%eax
0x400bf4  <+0x006b>        89 45 fc              mov    %eax,-0x4(%rbp)
        25 [1]	    write(n);
0x400bf7  <+0x006e>        8b 45 fc              mov    -0x4(%rbp),%eax
0x400bfa  <+0x0071>        89 c7                 mov    %eax,%edi
0x400bfc  <+0x0073>        e8 55 ff ff ff        callq  0x400b56 <write(int)>
        28 [1]	  initPointer();
0x400c01  <+0x0078>        e8 a7 fd ff ff        callq  0x4009ad <initPointer()>
        30 [1]	    n = ps->b_;
0x400c06  <+0x007d>        48 8d 05 a3 14 20 00  lea    0x2014a3(%rip),%rax        # 0x6020b0 <ps>
0x400c0d  <+0x0084>        48 8b 00              mov    (%rax),%rax
0x400c10  <+0x0087>        8b 40 04              mov    0x4(%rax),%eax
0x400c13  <+0x008a>        89 45 fc              mov    %eax,-0x4(%rbp)
        31 [1]	    write(n);
0x400c16  <+0x008d>        8b 45 fc              mov    -0x4(%rbp),%eax
0x400c19  <+0x0090>        89 c7                 mov    %eax,%edi
0x400c1b  <+0x0092>        e8 36 ff ff ff        callq  0x400b56 <write(int)>
        33 [1]	    n = pc->b_;
0x400c20  <+0x0097>        48 8d 05 91 14 20 00  lea    0x201491(%rip),%rax        # 0x6020b8 <pc>
0x400c27  <+0x009e>        48 8b 00              mov    (%rax),%rax
0x400c2a  <+0x00a1>        8b 40 04              mov    0x4(%rax),%eax
0x400c2d  <+0x00a4>        89 45 fc              mov    %eax,-0x4(%rbp)
        34 [1]	    write(n);
0x400c30  <+0x00a7>        8b 45 fc              mov    -0x4(%rbp),%eax
0x400c33  <+0x00aa>        89 c7                 mov    %eax,%edi
0x400c35  <+0x00ac>        e8 1c ff ff ff        callq  0x400b56 <write(int)>
        36 [1]	    n = pts->b_;
0x400c3a  <+0x00b1>        48 c7 c0 d8 ff ff ff  mov    $0xffffffffffffffd8,%rax
0x400c41  <+0x00b8>        64 48 8b 00           mov    %fs:(%rax),%rax
0x400c45  <+0x00bc>        8b 40 04              mov    0x4(%rax),%eax
0x400c48  <+0x00bf>        89 45 fc              mov    %eax,-0x4(%rbp)
        37 [1]	    write(n);
0x400c4b  <+0x00c2>        8b 45 fc              mov    -0x4(%rbp),%eax
0x400c4e  <+0x00c5>        89 c7                 mov    %eax,%edi
0x400c50  <+0x00c7>        e8 01 ff ff ff        callq  0x400b56 <write(int)>
        39 [1]	    n = ptc->b_;
0x400c55  <+0x00cc>        48 c7 c0 e0 ff ff ff  mov    $0xffffffffffffffe0,%rax
0x400c5c  <+0x00d3>        64 48 8b 00           mov    %fs:(%rax),%rax
0x400c60  <+0x00d7>        8b 40 04              mov    0x4(%rax),%eax
0x400c63  <+0x00da>        89 45 fc              mov    %eax,-0x4(%rbp)
        40 [1]	    write(n);
0x400c66  <+0x00dd>        8b 45 fc              mov    -0x4(%rbp),%eax
0x400c69  <+0x00e0>        89 c7                 mov    %eax,%edi
0x400c6b  <+0x00e2>        e8 e6 fe ff ff        callq  0x400b56 <write(int)>
        42 [1]	    n = ptls->b_;
0x400c70  <+0x00e7>        e8 d7 00 00 00        callq  0x400d4c <_ZTW4ptls>
0x400c75  <+0x00ec>        48 8b 00              mov    (%rax),%rax
0x400c78  <+0x00ef>        8b 40 04              mov    0x4(%rax),%eax
0x400c7b  <+0x00f2>        89 45 fc              mov    %eax,-0x4(%rbp)
        43 [1]	    write(n);
0x400c7e  <+0x00f5>        8b 45 fc              mov    -0x4(%rbp),%eax
0x400c81  <+0x00f8>        89 c7                 mov    %eax,%edi
0x400c83  <+0x00fa>        e8 ce fe ff ff        callq  0x400b56 <write(int)>
        45 [1]	    n = ptlc->b_;
0x400c88  <+0x00ff>        e8 e9 00 00 00        callq  0x400d76 <_ZTW4ptlc>
0x400c8d  <+0x0104>        48 8b 00              mov    (%rax),%rax
0x400c90  <+0x0107>        8b 40 04              mov    0x4(%rax),%eax
0x400c93  <+0x010a>        89 45 fc              mov    %eax,-0x4(%rbp)
        46 [1]	    write(n);
0x400c96  <+0x010d>        8b 45 fc              mov    -0x4(%rbp),%eax
0x400c99  <+0x0110>        89 c7                 mov    %eax,%edi
0x400c9b  <+0x0112>        e8 b6 fe ff ff        callq  0x400b56 <write(int)>
        48 [1]	}
0x400ca0  <+0x0117>        b8 00 00 00 00        mov    $0x0,%eax
0x400ca5  <+0x011c>        c9                    leaveq
0x400ca6  <+0x011d>        c3                    retq
