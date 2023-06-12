
## c++ class

### 完美转发
```
void func(T&& param) {
    // auto p = new T();
}
func(5)
int i = 5;
func(i)
这里传进来的param可以是lvalue，也可以是rvalue
T可能是int&，也可能是int，如果我在func里用new来创建一个指针时，这个T可能是int&
所以要用typename std::decay<T>::type == int(这是我想要的)
    
template<typename T> void f(T&&);
int main() {
    std::string s;
    f(s); // T is std::string&
    const std::string s2;
    f(s2); // T is a const std::string&
}
```








