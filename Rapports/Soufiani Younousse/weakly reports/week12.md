## <p align=center> Session 15
<ins>28/02</ins>
Work on the program: i have tryed a new way to cut the slither program with a "switch-case", but i could not test this [new program](https://github.com/YOUSSNDR/PolySnake/blob/b902d92297fb181699cc290238d12c17dca581ae/programmes/test/test%20mouvement/snakewalk-case4.ino/snakewalk-case4.ino.ino) yet.
here we only kept four cases as said in the last session:
- line (snake in line)
- slither (the snake go forward)
- slither right (the snake take a right turn)
- slither left (the snake take a left turn)
- stop (the snake stop his mouvement)

Also we will have to modify another point on the slither program so that we can get an endless loop which the "switch-case" will modify.


Verification of the component, as the Raspberry pi zero 2W is on limited stock it was much harder to found, We finally selected [this product](https://fr.aliexpress.com/item/1005003496928208.html?spm=a2g0o.productlist.main.21.3f417lne7lneUU&algo_pvid=c0582096-af5e-4bd4-b745-91c9b46bf610&algo_exp_id=c0582096-af5e-4bd4-b745-91c9b46bf610-10&pdp_ext_f=%7B%22sku_id%22%3A%2212000026058357679%22%7D&pdp_npi=3%40dis%21EUR%21117.15%21107.78%21%21%21%21%21%402145265416775739405673798d06e0%2112000026058357679%21sea%21FR%210&curPageLogUid=PvRLIFtbqjUQ).


I have also worked on another way to work with the raspberry pi (if equiped with wifi) by using ssh.
It is not finished yet but i am also writing down all the details on how to connect the raspberry pi so that the tutorial could be used for the next Raspberry pi and also by someone else.
Here is the [tutorial](https://github.com/YOUSSNDR/PolySnake/blob/b902d92297fb181699cc290238d12c17dca581ae/Raspberry%20pi/Raspberry%20pi%20zero%20config/config%20Raspberry%20pi%20zero%20W.md) (not finished yet).