/*
 * 01
 * 为 cMyString 添加赋值运算符.
 */

#include <cstring>
#include <cstdio>
#include <iostream>

class CMyString {
public:
    CMyString(char *p = nullptr);   
    CMyString(const CMyString&);

    CMyString & operator=(const CMyString &);
    
    void print();
    
    ~CMyString();
private:
    char *m_pData;
};

inline CMyString::CMyString(char *p) {
    if (p == nullptr) {
        m_pData = new char[1]; 
        m_pData[0] = '\0';
    } else {
        size_t len = strlen(p); 
        m_pData = new char[len+1];
        strcpy(m_pData, p);
    }
}

inline CMyString::CMyString(const CMyString &lhs) {
    size_t len = strlen(lhs.m_pData);
    m_pData = new char[len+1];
    strcpy(m_pData, lhs.m_pData);
}

inline CMyString& CMyString::operator=(const CMyString &lhs) {
    if (this != &lhs) {
        CMyString mTempt(lhs); 
        char *pTemp = mTempt.m_pData;
        mTempt.m_pData = m_pData;
        m_pData = pTemp;
    }
    return *this;
}

inline void CMyString::print() {
    printf("%s", m_pData);
}

inline CMyString::~CMyString() {
    delete[] m_pData;
}

//=============================================================================
//           Test Fuction
//=============================================================================

void testFundation() {
    printf("## Test for basic function begin\n");
    char text[] = "hello first test";
    CMyString test1(text);

    CMyString test2 = test1;
    
    printf("expected output is: %s\n", text);
    printf("test1 is : \n");
    test1.print();
    printf("\n");
    
    printf("expected output is: %s\n", text);
    printf("test2 is : \n");
    test2.print();
    printf("\n");

    printf("## Test for assigning to itself\n");
    test2 = test2;
    printf("expected output is: %s\n", text);
    printf("result is : \n");
    test2.print();
    printf("\n");
    
    printf("## Test for assigning consecutively \n");
    char text2[] = "assignment test";
    CMyString temp(text2);
    CMyString test3 = test2 = temp;
    printf("expected output is: %s\n", text2);
    printf("result is : \n");
    test2.print();
    printf("\n");

    printf("expected output is: %s\n", text2);
    printf("result is : \n");
    test3.print();
    printf("\n");
}

int main() {
    testFundation();
    return 0;
}



