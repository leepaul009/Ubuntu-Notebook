
### 1. plugin creator
Create a plugin creator and implement neccessay methods.
```
class plugin_creator_name : public BaseCreator
```
The plugin creator will be used in parser.
For example, parser use it to get a pluginCreator with plugin name and version. 
```
# for example of OP: NMS, version: 0
const std::string pluginName = "NMS";
const std::string pluginVersion = "0";
const auto mPluginRegistry = getPluginRegistry();
const auto pluginCreator = mPluginRegistry->getPluginCreator(pluginName.c_str(), pluginVersion.c_str());
```
Then create a plugin by using pluginCreator. (DEFINE_BUILTIN_OP_IMPORTER(new_op) in ./parsers/onnx/builtin_op_importers.cpp)
```
nvinfer1::PluginFieldCollection fc;
...
auto plugin = pluginCreator->createPlugin(node.name().c_str(), &fc);
```

### 2. plugin
Create plugin class and implement neccessay methods.
```
class plugin_name : public IPluginV2Ext
```
#### 2.1 import methods
```
# return type and version, which are corresponded to 'pluginName' and 'pluginVersion' of plugin creator.
const char* getPluginType() const override;
const char* getPluginVersion() const override;

# get parameters from the input 'fc'.
void setParametersFromPluginFields(const PluginFieldCollection* fc);

# return workspace size. workspace is all the GPU buffer used in "enqueue(...)"
size_t getWorkspaceSize(int maxBatchSize) const override;

# return the dimension of outputs
Dims getOutputDimensions(int index, const Dims* inputs, int nbInputDims) override;

# 'main function' of the plugin
int enqueue(int batch_size, const void* const* inputs, void** outputs, void* workspace, cudaStream_t stream) override;
```
