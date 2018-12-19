#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <functional>
#include <array>
#include <cmath>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <sstream>
#include <string.h>


using namespace std;

struct Cat {
    int height;
    string name;

    Cat(int h, string n) : height(h), name(n){}
};

struct Ad;
Ad* _ad;

struct Ad {
    Cat _cat;
    Cat* mutable_cat() {
        return &_ad->_cat;
    }
    Ad(Cat c) : _cat(c) {}
};



template <class T, class U = std::greater<>> // std::greater<> require C++14
void bubbleSort(T begin, T end, U comp = U())
{
    for(auto i = end-1; i != begin; i--) {
        for(auto j = begin; j != i; j++) {
            if(comp(*j, *i)) {
                std::swap(*j, *i);
            }
        }
    }
}

template <class T, class U = std::greater<>> // std::greater<> require C++14
void bubbleSort2(T begin, T end, U comp = U())
{
    auto low = begin;
    auto high = end;
    while(low < high) {
        for(auto i = low; i != high; i++) {
            if(comp(*i, *(i + 1))) {
                std::swap(*i, *(i + 1));
            }
        }
        high--;
        for(auto i = high; i != low; i--) {
            if(comp(*(i - 1), *i)) {
                std::swap(*i, *(i - 1));
            }
        }
        low++;
    }
}

struct filtered_info {
    uint32_t is_hard_thres_filter;
    uint32_t hard_thres_filter_symbol;
    std::string hard_thres_filter_mts;
    uint32_t is_soft_thres_filter;
    float soft_thres_query_title_sim;
    float soft_thres_query_desc_sim;
    float soft_thres_sim;
    float soft_thres_query_title_con;
    float soft_thres_query_desc_con;
    float soft_thres_con;
    float soft_thres_sim_thr;
    float soft_thres_con_thr;
    std::string soft_thres_filter_mts;

    filtered_info() {
        memset(this, 0, sizeof(filtered_info));
        is_hard_thres_filter = 1;
    }

    float print(float f1 = 2.0) {
        return f1;
    }
};

void test_append_func() {
    char b[5] = "456";
    cout << "b:" << b << endl;
}

void test_lifecycle() {
    for (int i = 0; i < 5; ++i) {
        char a[5] = {0};
        string str;
        int j;
        if (i == 0) {
            strcpy(a, "123");
            str = "str123";
            j = 110;
        }
        cout << i << ":" << a << ":" << &a << endl;
        cout << i << "#" << str << ":" << &str << endl;
        cout << i << "$" << j << ":" << &j << endl;
    }
}

int main() {
    test_lifecycle();

//    char a[] = "www%2Ejd%2Ecom";
//    cout << a << endl;

//    bool a = false;
//    bool b = true;
//    uint32_t  c = 100;
//    uint32_t  d = 100;
//    c += (1000*a);
//    d += (1000*b);
//
//    cout << 25*a << ":" << 30*b << endl;
//    cout << c << endl;
//    cout << d << endl;

//    char c[5];
//    for (int i =0; i < 5; ++i) {
//        if (c[i] == '\0') {
//            cout << "0" << endl;
//        } else {
//            cout << "not" << endl;
//        }
//    }

//    const char* a = "abcdefg";
//    const char* b = "def";
//    const char* c = NULL;
//    const char* d = NULL;
//    cout << (c[0] == '\0') << endl;
//    if (c = '\0') {
//        cout << "" ;
//    }
//    if (strstr(d,c)) {
//        cout << "a contains b" << endl;
//    } else {
//        cout << "a not contains b" << endl;
//    }

//    std::ostringstream oss;
//    string s = "123";
//    oss << s << ":" << s.c_str();
//    cout << oss.str() << endl;

//    std::ostringstream oss;
//    oss << 123 << std::string("#").c_str() << "abc" << 56;
//    std::string ostr = oss.str();
//    cout << ostr << endl;

//    oss.str("");
//    oss << "ano" << "#" << false << "#" << true;
//    cout << oss.str() << endl;

//    std::set<uint32_t> mt_set;
//    mt_set.insert(1);
//    mt_set.insert(2);
//    mt_set.insert(2);
//    mt_set.insert(3);

//    std::string pa_mts = "123,345,222";
//    std::set<std::string> mt_set2;
//    boost::split(mt_set2, pa_mts, boost::is_any_of(","));

//    std::vector<uint32_t> pa_mt_vec;
//    pa_mt_vec.push_back(1);
//    pa_mt_vec.push_back(15);
//    pa_mt_vec.push_back(666);

//    mt_set.insert(pa_mt_vec.begin(), pa_mt_vec.end());

//    mt_set.insert(mt_set2.begin(), mt_set2.end());

//    std::string debuginfo;
//    std::set<uint32_t>::const_iterator it = mt_set.begin();
//    for (; it != mt_set.end(); ++it) {
//        debuginfo.append(std::to_string(*it));
//        debuginfo.append("#");
//        cout << *it << endl;
//    }
//
//    cout << debuginfo << endl;
//
//    if (mt_set.find(2) == mt_set.end()) {
//        cout << "2 not found" << endl;
//    } else {
//        cout << "2 found" << endl;
//    }


//    filtered_info fi;
//    cout << fi.hard_thres_filter_mts << endl;
//    cout << fi.soft_thres_query_title_sim << endl;
//    cout << fi.is_hard_thres_filter << endl;
//    char a[] = "abc";
//    char b[] = "abcd";
//    bool is_equal = strcmp(a,b);
//    cout << is_equal << endl;
//    uint32_t is_titlekg_badcase = 1;
//    uint32_t is_desckg_badcase = 0;
//    uint32_t is_hard_thres_filtered = 1;
//    uint32_t is_soft_thres_filtered = 0;
//    uint32_t ad_kg_status = 0;
//    uint32_t filter_status_list[] = {is_soft_thres_filtered, is_hard_thres_filtered, is_desckg_badcase, is_titlekg_badcase};
//    int tail_idx_filter_status =  sizeof(filter_status_list) / sizeof(uint32_t) - 1;;
//    for (int i = tail_idx_filter_status; i >= 0; --i) {
//        ad_kg_status += filter_status_list[i] * pow(10, tail_idx_filter_status - i);
//        cout << ad_kg_status << endl;
//    }
//    cout << ad_kg_status << endl;

//    std::array<int, 10> s = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
//    bubbleSort(s.begin(), s.end());

//    for(auto i = 0; i < s.size(); i++) // Loop1
//        std::cout << s.at(i) << " ";
//
//    std::cout << std::endl;

//    for (auto a : s) { // Loop2
//        std::cout << a << " ";
//    }

//    uint32_t weight = 300000;
//    uint32_t u = 1e6;
//    float out = (float)weight/u;
//    cout << out << endl;
//    uint32_t a = 1;
//    float b = 0.24;
//    a = b;
//    cout << a << " " << b << endl;
//    float a = 0.000001;
//    cout << a << endl;
//    filtered_info fi;
//    float a = fi.print(3.0);
//
//    cout << fi.is_hard_thres_filter << endl;
//    cout << fi.hard_thres_filter_symbol << endl;
//    cout << fi.soft_thres_query_desc_sim << endl;
//    if (std::string("") == fi.hard_thres_filter_mts) {
//        cout << "is empty" << endl;
//    } else {
//        cout << "is not empty" << endl;
//    }
//    cout << a << endl;

//    cout <<fi.is_hard_thres_filter<<endl;
//    cout << fi.hard_thres_filter_mts<<endl;
//    cout << fi.soft_thres_query_title_sim<<endl;

//    Cat c1(0,"miao");
//    _ad = new Ad(c1);
//
//    cout << _ad->_cat.name << endl;
//
//    Cat c2(1, "hhh");
//    *_ad->mutable_cat() =  c2;
//
//    cout << _ad->_cat.name << endl;

//    enum {
//        A = 0,
//        B = 1,
//        C = 4,
//    }en;
//
//    cout << B << endl;

//    char s[6] = "abcde";
//    cout << s << endl;
//    string str = s;
//    string a = "hhh";
//    cout << str << endl;
//    std::cout << "Hello, World!" << std::endl;
//    std::vector<int> vec = {1,2,3};
//    std::cout << vec[0] << std::endl;
//
//    set<int> s = {4,5,6};
//    for (auto i : s) {
//        cout << i << endl;
//    }
//
//    stack<int> st;
//    st.push(7);
//    st.push(8);
//    cout << st.top() << endl;

    return 0;
}