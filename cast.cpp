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
    void (B::*pbm)() = static_cast<void (B::*)()>(pcm); // VS2012 says: warning C4407: ��ָ���Ա��ʾ��ʽ�Ĳ�ָͬ��֮�����ת�����������������ɲ���ȷ�Ĵ���
    (pb->*pbm)();
 
    // case 2:   5.2.10.9 ISO/IEC 14882:2003(E)
    pbm = reinterpret_cast<void (B::*)()>(pcm); // VS2012 says :error C2440: ��reinterpret_cast��: �޷��ӡ�void (__thiscall C::* )(void)��ת��Ϊ��void (__thiscall B::* )(void)��
    // ����,static_cast ���ܹ���,reinterpret_cast�ͱ������.reinterpret_castֻ�Ǽ򵥵�ͨ�������ƽ������½��ͣ�û���κε����ͼ�⣡
	std::cout << sizeof(&B::bfun)<<std::endl;
    system("pause");
    return 0;
};