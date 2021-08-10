### install
```
## envs (torch16-py38):
conda create -n torch16-py38 python=3.8
conda install pytorch==1.6.0 torchvision==0.7.0 cudatoolkit=10.2 -c pytorch -y
conda install -c conda-forge opencv -y
conda install tqdm scipy -y

## this will install in conda env
pip install git+https://github.com/philferriere/cocoapi.git#subdirectory=PythonAPI
## or pip install pycocotools

## test cuda in torch:
torch.cuda.current_device()
print(torch.tensor([1.0, 2.0]).cuda())
```


