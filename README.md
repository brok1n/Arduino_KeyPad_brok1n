# KeyPad_brok1n  version:0.0.1
arduino Matrix keyboard library

学习arduino 矩阵键盘的过程中。写的一个4*4矩阵键盘库。可以直接定义按下矩阵键盘要显示出来的字符 按下键之后。就可以得到你定义的按下键的字符

本库目前只适合4*4矩阵键盘。后期有空可能会考虑升级支持其他形式的矩阵键盘。

使用时。只需要定义矩阵键盘上你要按键后显示的字符的数组。和矩阵键盘连接的引脚数组即可。

将本库代码下载后。解压后得到KeyPad_brok1n文件夹 将这个文件夹里的 .git 文件夹删除
然后将KeyPad_brok1n文件夹放到arduino安装目录下的library 目录下。

重新打开arduino ide  然后在  文件 -》示例 -》 KeyPad_brok1n -》 Example -》Keypad_Brok1n_example  就可以看到示例了。


如果你发现按键和获得的字符不匹配。可以试着将 keyPin 二维数组的 第一行和第二行调换一下位置

