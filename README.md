给定一个数独，未填的空格用“0”表示。每两个数字之间用一个空格隔开。求解。
算法思路:设计a,b,c三个数组储存数独行，列， 宫三种限制，用压缩二进制数存储，cnt[x]表示二进制数x中1的个数。每次dfs中，先找出限制最多的未填格子，在此格子中填入合法的数，并更新a,b,c继续dfs.直到填完所有格子。
