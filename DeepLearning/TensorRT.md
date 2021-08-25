

### 1.1 Create TensorRT Engine

#### 1.1.1 Create inferBuilder, network and builderConfig
```
auto builder = SampleUniquePtr<nvinfer1::IBuilder>(nvinfer1::createInferBuilder(gLogger.getTRTLogger()));
if (!builder) return false;

const auto explicitBatch = 1U << static_cast<uint32_t>(nvinfer1::NetworkDefinitionCreationFlag::kEXPLICIT_BATCH);
auto network = SampleUniquePtr<nvinfer1::INetworkDefinition>(builder->createNetworkV2(explicitBatch));
if (!network) return false;

auto config = SampleUniquePtr<nvinfer1::IBuilderConfig>(builder->createBuilderConfig());
if (!config) return false;

```

#### 1.1.2 Create parser and parse the model
```
auto parser = SampleUniquePtr<nvonnxparser::IParser>(nvonnxparser::createParser(*network, gLogger.getTRTLogger()));
if (!parser) return false;
...
auto parsed = parser->parseFromFile(PATH_TO_ONNX_FILE, static_cast<int>(gLogger.getReportableSeverity()));
```

#### 1.1.3 Create engine. samplesCommon::InferDeleter() help to automatically delete engine object.
```
mEngine = std::shared_ptr<nvinfer1::ICudaEngine>(builder->buildEngineWithConfig(*network, *config), samplesCommon::InferDeleter());
if (!mEngine) return false;

```

#### 1.2 Inference with TensorRT Engine

#### 1.2.1 prepare host/device buffer and process input
prepare host/device buffer
read input into host buffer, then host buffer could be copied into device buffer

#### 1.2.2 inference
before do inference, we need to copy input to GPU buffer
```
auto context = SampleUniquePtr<nvinfer1::IExecutionContext>(mEngine->createExecutionContext());
bool status = context->execute(mParams.batchSize, buffers.getDeviceBindings().data());
```
copy output from GPU buffer and do verification to inference output

