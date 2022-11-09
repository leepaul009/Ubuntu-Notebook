##### Why would I want to std::move an std::shared_ptr?
```
a_vector.emplace_back(std::move(a_shared_pointer));
```
std::shared_ptr reference count is atomic. increasing or decreasing the reference count requires atomic increment or decrement. This is hundred times slower than non-atomic increment/decrement, not to mention that if we increment and decrement the same counter we wind up with the exact number, wasting a ton of time and resources in the process.


##### template
```
## template with default argument
template <typename T = int>
class Foo{};
## before C++17:
Foo<> f;
## C++17:
Foo f;
```

##### shared_ptr不能循环引用
```
class Observer; // 前向声明
class Subject {
private:
    std::vector<shared_ptr<Observer>> observers;
public:
    Subject() {}
    addObserver(shared_ptr<Observer> ob) {
        observers.push_back(ob);
    }
    // 其它代码
    ..........
};
class Observer {
private:
    shared_ptr<Subject> object;
public:
    Observer(shared_ptr<Object> obj) : object(obj) {}
    // 其它代码
    ...........
};
```
有一个变量shared_ptr<Subject> p，此时，p指向的对象不仅通过该shared_ptr引用自己，还通过它包含的Observer中的object成员变量引用回自己，于是它的引用计数是2，每个Observer的引用计数都是1。当p析构时，它的引用计数减1，变成2-1=1（大于0!），p指向对象的析构函数将不会被调用，于是p和它包含的每个Observer对象在程序结束时依然驻留在内存中没被delete，形成内存泄漏。

