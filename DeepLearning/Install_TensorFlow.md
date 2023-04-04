### tensorflow dep version
```
https://www.tensorflow.org/install/source#tested_build_configurations
```

### Install tensorflow 1.15 with conda
```
conda create -n tf1.15 python=3.6
conda activate tf1.15
conda install tensorflow-gpu=1.15 # will auto-install cudatoolkit10.0 and cudnn7.6.5
conda install jupyterlab notebook
```


### install tensorflow with conda
```
conda create -n tf-gpu tensorflow-gpu

# pip install bert-tensorflow
conda install -c conda-forge bert-tensorflow
conda install -c conda-forge tensorflow-hub

conda install -c conda-forge tensorflow-text

conda install -c conda-forge scikit-learn
```

### install tensorflow with pip
```
# Requires the latest pip
pip install --upgrade pip

# Current stable release for CPU and GPU
pip install tensorflow

# Or try the preview build (unstable)
pip install tf-nightly
```
