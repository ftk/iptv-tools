# convert text as if it was typed on russian keyboard layout
iconv -t cp1251 -f utf-8 | tr 'qwertyuiop[]asdfghjkl;'"'"'zxcvbnm,.' 'יצףךוםדרשחץתפûגאןנמכהז‎ÿקסלטעüב‏' | iconv -f cp1251 -t utf-8
