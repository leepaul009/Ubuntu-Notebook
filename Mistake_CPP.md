## does not imtermediately mange resource after request the resource:
```
func(std::shared_ptr<Item>(new Item), other_parameters)
# run in order: "new Item", other_parameters, error, std::shared_ptr<Item>
# new created Item will not be managed by shared_ptr
```
