echo 'VM:'
echo 'Big champ: ./corewar test_champs/kilochamp.cor'
./corewar test_champs/kilochamp.cor
echo ''
echo 'Size diff from header: ./corewar test_champs/invldheader.cor'
./corewar test_champs/invldheader.cor
echo ''
echo 'Extra zeroes in .cor: ./corewar test_champs/extra_zs.cor'
./corewar test_champs/extra_zs.cor
echo ''
echo 'Removed zeroes in .cor: ./corewar test_champs/rem_zs.cor'
./corewar test_champs/rem_zs.cor
echo ''
echo 'No code: ./corewar test_champs/nocode.cor'
./corewar test_champs/nocode.cor
echo ''
echo ''
echo 'ASM:'
echo 'Nameless champ: ./asm test_champs/nameless.s'
./asm test_champs/nameless.s
echo ''
echo 'Commentless champ: ./asm test_champs/commentless.s'
./asm test_champs/commentless.s
echo ''
echo 'Empty name: ./asm test_champs/emptyname.s'
./asm test_champs/emptyname.s
echo ''
echo 'Empty comment: ./asm test_champs/emptycomment.s'
./asm test_champs/emptycomment.s
echo ''
echo 'Name too long: ./asm test_champs/longname.s'
./asm test_champs/longname.s
echo ''
echo 'Comment too long: ./asm test_champs/longcom.s'
./asm test_champs/longcom.s
echo ''
echo 'Invalid label: ./asm test_champs/invldlab.s'
./asm test_champs/invldlab.s
echo ''
echo 'No code: ./asm test_champs/nocode.s'
./asm test_champs/nocode.s
echo ''
echo 'Testing Complete!'