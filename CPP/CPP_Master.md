##### Why would I want to std::move an std::shared_ptr?
```
a_vector.emplace_back(std::move(a_shared_pointer));
```
std::shared_ptr reference count is atomic. increasing or decreasing the reference count requires atomic increment or decrement. This is hundred times slower than non-atomic increment/decrement, not to mention that if we increment and decrement the same counter we wind up with the exact number, wasting a ton of time and resources in the process.


