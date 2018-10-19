#include <iostream>
#include <string>
#include <map>
#include <stack>

std::string filter(const std::string &str) {
	std::map<int, int> matches;
	std::stack<int> st;
	int pos = 0;
	for (auto &c : str) {
		if (c == '(') {
			st.push(pos);
		} else if (c == ')') {
			if (st.size()) {
				auto x = st.top(); st.pop();
				matches[x] = pos;
				matches[pos] = x;
			} else {
				matches[pos] = -1;
			}
		}
		++pos;
	}
	pos = 0;
	std::string ret;
	for (auto &c : str) {
		if (c == '(' || c == ')') {
			auto iter = matches.find(pos);
			if (iter != matches.end() && iter->second != -1) {
				ret += c;
			}
		} else {
			ret += c;
		}
		pos++;
	}
	return ret;
}

int main() {
	std::cout << filter("()") << std::endl;
	std::cout << filter("())") << std::endl;
	std::cout << filter("(()") << std::endl;
	std::cout << filter("(ab)c)(d)") << std::endl;
	std::cout << filter("(a(b(b)d)(e)(f))") << std::endl;
	return 0;
}