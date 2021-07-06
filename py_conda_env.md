## Conda
### conda export env to yml file
```
conda env export > ***.yml
```
### conda import env from yml file
```
conda env create -f ***.yml
```

### Jupyter setup
```
jupyter notebook --generate-config

jupyter notebook password

vim ~/.jupyter/jupyter_notebook_config.py
c.NotebookApp.ip='*'
c.NotebookApp.password = u'sha1:f9030dd55bce:75fd7bbaba41be6ff5ac2e811b62354ab55b1f63'
c.NotebookApp.open_browser = False
c.NotebookApp.port =8888
c.NotebookApp.allow_remote_access = True
```
