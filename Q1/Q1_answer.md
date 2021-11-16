Below diagram shows the pre and post bitband assemby instruction set,

![with BitBand](https://github.com/girichou/EMBSYS310A/blob/master/Q1/Q1_a_bitband.png)
![without BitBand]https://github.com/girichou/EMBSYS310A/blob/master/Q1/Q1_b_wo_bitband.png

As you can see, without bitband to update a bit it tool 2 instruction cycle instead of single instruction.

BitBanding is atomic in nature so interrupts are unable to modify the data.
