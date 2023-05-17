

### contingency plan:
In a scenario that we could either accelerate or decelerate, we can plan 2 trajectories at one time. <br />
And try to make 2 trajectories have a same part from the beginning to the breaking point. <br />
After breaking point, it branch into 2 trajectories. 
```
      breaking point
------------ o -------------
               -------------
```
During optimzation, state to be optimized includes both state of 2 trajectories. <br />
Cost function will encourage 2 trajectories merge before breaking point. <br />
But we can not guarantee just merge in breaking point, it could merge a little bit far from breaking point<br />






