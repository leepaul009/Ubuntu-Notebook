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



### Intr
what is anchors(grid anchor)?
```
A grid anchor is {x1,y1,x2,y2}, first pt{x1,y1} is left top and another is right bottom point, whose unit is input image coordinate.
The anchor is reconstructed as a "box" for later usage.
```
what is rpn head?
```
RPN head take featrue maps to produce "logic"[N, 3, H, W], "box detals"[N, 3*4, H, W].
Each box detals is a prediction of box, which has:
detals is {dcx,dcy,dw,dh}
pred_cx = dcx * anchor_w + anchor_cx
pred_w = exp(dw) * anchor_w
```

