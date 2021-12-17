#ifdef WIN32
#pragma comment(lib, "tributary")
#endif

#include <iostream>
#include <cppcoro/sync_wait.hpp>
#include <tributary/streaming.hpp>
#include <tributary/utils.hpp>

using namespace tributary::streaming;
using namespace tributary::utils;
using namespace std;

int func() { return 1;} 

int main() {
    cout << "Export check: " << streamingExportCheck() << endl;

    cout << "*******************************************" << endl;

    Node n(generator);
    // cout << n << endl;
    cout << n() << endl;
    cout << n() << endl;
    cout << n() << endl;
    cout << n() << endl;

    cout << "*******************************************" << endl;

    cout << cppcoro::sync_wait(asyncFunctionCoro()) << endl;
    cout << cppcoro::sync_wait(asyncFunctionCoro()) << endl;
    cout << cppcoro::sync_wait(asyncFunctionCoro()) << endl;
    cout << cppcoro::sync_wait(asyncFunctionCoro()) << endl;

    cout << "*******************************************" << endl;

    // function<cppcoro::task<int>()> foo = tributary::streaming::convertToCoroutine<function<int()>>(func);
    function<cppcoro::task<int>()> foo = tributary::streaming::convertToCoroutine(generator);
    cout << cppcoro::sync_wait(foo()) << endl;
    cout << cppcoro::sync_wait(foo()) << endl;
    cout << cppcoro::sync_wait(foo()) << endl;
    cout << cppcoro::sync_wait(foo()) << endl;

    cout << "*******************************************" << endl;


}
