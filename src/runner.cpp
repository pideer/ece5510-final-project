#include "runner.hpp"

using namespace std;

enum LockType { hashCpu, spinGpu, chained, cuckoo, empty };

LockType convertType(string input) {
    static const std::unordered_map<string, LockType> table = {
        {"hashCpu", LockType::hashCpu},
        {"spinGpu", LockType::spinGpu},
        {"chained", LockType::chained},
        {"cuckoo", LockType::cuckoo}};
    auto it = table.find(input);
    return (it != table.end()) ? it->second : LockType::empty;
}

int run(const vector<string> &args, const string type) {
    auto ctype = convertType(type);

    switch (ctype) {
    case hashCpu:
        /* code */
        break;
    case spinGpu:
        /* code */
        break;
    case chained:
        /* code */
        break;
    case cuckoo:
        /* code */
        break;

    default:
        return 1;
    }
    return 0;
}