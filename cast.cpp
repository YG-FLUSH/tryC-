#include <iostream>
#include <string>
class A
{
public:
    void afun()
    {
        std::cout << am;
    }
    std::string am;
};
 
class B
{
public:
    void bfun()
    {
        std::cout << bm;
    }
    std::string bm;
};
 
class C:public A,public B
{
public :
    void cfun()
    {
        std::cout << cm;
    }
    std::string cm;
};
 
 
int main()
{
    C ci;
    ci.am = "aaaaa";
    ci.bm = "bbbbb";
    ci.cm = "ccccc";
    B * pb = &ci;
 
    // case 1:     5.2.9.9 ISO/IEC 14882:2003(E) 
    void (A::*pam)() = &A::afun;
    void (C::*pcm)() = &C::cfun;
    void (B::*pbm)() = static_cast<void (B::*)()>(pcm); // VS2012 says: warning C4407: 在指向成员表示形式的不同指针之间进行转换，编译器可能生成不正确的代码
    (pb->*pbm)();
 
    // case 2:   5.2.10.9 ISO/IEC 14882:2003(E)
    pbm = reinterpret_cast<void (B::*)()>(pcm); // VS2012 says :error C2440: “reinterpret_cast”: 无法从“void (__thiscall C::* )(void)”转换为“void (__thiscall B::* )(void)”
    // 你妹,static_cast 都能过的,reinterpret_cast就变错误了.reinterpret_cast只是简单的通过二进制进行重新解释，没有任何的类型检测！
	std::cout << sizeof(&B::bfun)<<std::endl;
    system("pause");
    return 0;
};