
### 
Calculates the terminal velocity for an exponential decay in acceleration.
assumes exponential decay acceleration model:
```
# decay_factor = -0.3,then a_end will drop upto 0.1 after 8 seconds.
a_end = a_initial * exp(decay_factor * t)
v_end = a_initial / decay_factor * ( exp(decay_factor  * t) - 1) + v_initial
v_final = v_initial - a_initial / decay_factor  (asymptote, as t -> infinity)
```

Final 1D velocity given initial velocity, acceleration, time delta and decay factor (negative!)
assumes exponential decay acceleration model:
```
a_end = acc * exp(decay_factor  * t)
      = a_init * exp( log(0.1)/8 * t )
      = a_init * exp( -log(10) * t/8 )
      = a_init * exp( -2.30 * t/8 ) ### Note: exp(-2.3)=0.1 that indicates we finially get a_end=0.1*a_init
v_end = acc / decay_factor * exp(decay_factor  * t) + v_initial - acc / decay_factor
      = acc / decay_factor * ( exp(decay_factor  * t) - 1) + v_initial
v_end = a_end / decay_factor + v_init - a_init / decay_factor
      = v_init + (a_end - a_init) / decay_factor, where decay_factor = log(0.1)/8
      = v_init + (a_end - a_init) * 8 / log(0.1)
      = v_init + (a_end - a_init) * 8 / ( log(1) - log(10) )
      = v_init + (a_init - a_end) * 8 / ( log(10) - log(1) )
      = v_init + (a_init - a_end) * 8 / 2.30   ### Note: devide 2 indicats linear decrease of acc
      Int[ exp( log(0.1) * T ) ] - 0.1*T, where T = 0~1 and T = t/8
      = 1/log(0.1) * exp(log(0.1) * T) - 0.1*T

```

/// Compute the time to reach a velocity given initial velocity, acceleration and decay factor
/// NOTE: assumes exponential decay acceleration model
/// v_end = acc / decay_factor * ( exp(decay_factor  * t) - 1) + v_initial
/// t =  ln(((v - v_inital) * decay_factor / acc) + 1) / decay_factor

/// Compute the time to reach a velocity given initial velocity, acceleration and decay factor
/// NOTE: assumes exponential decay acceleration model
/// s =  acc / decay_factor² * ( exp(decay_factor  * t) - 1) + ( v_initial - acc / decay_factor ) * t + s_init
/// t =  ln((v - v_inital) * decay_factor * acc + 1) / decay_factor
