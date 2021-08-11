# Conda
## Conda env
```
### conda export env to yml file
conda env export > ***.yml

### conda import env from yml file
conda env create -f ***.yml

### create
conda create -n paul-py3 python=3.

### clone
conda create --name myclone --clone myenv

### list installed
conda list | grep torch

### remove env and all its packages:
conda remove --name myenv --all
# or: conda remove --name myenv --all
# verify: conda info --envs
```


### Tensorflow
```
# isntall Tensorflow2.x:
conda create -n paul-tf-gpu tensorflow-gpu
```

```
conda install pytorch torchvision torchaudio cudatoolkit=10.2 -c pytorch
```

### Jupyter setup
```
conda install -c conda-forge notebook
pip install notebook

jupyter notebook --generate-config

jupyter notebook password

vim ~/.jupyter/jupyter_notebook_config.py
c.NotebookApp.ip='*'
c.NotebookApp.password = u'sha1:f9030dd55bce:75fd7bbaba41be6ff5ac2e811b62354ab55b1f63'
c.NotebookApp.open_browser = False
c.NotebookApp.port =8888
c.NotebookApp.allow_remote_access = True
```
