set background=dark 
syntax on
set mouse=a
set mousehide
set encoding=utf-8
scriptencoding utf-8
set backup "undo?
set cursorline "高亮当前行
set number "行数
set autoindent "自动缩进
set smartindent "智能缩进
set cindent "C系列缩进
set softtabstop=4 "缩进长度
set shiftwidth=4 "缩进长度
set tabstop=4 "tab键长度
colorscheme desert "配色沙漠 还有: torte, ron  等景点配色
filetype on "检查文件类型
set showmatch "自动匹配
set ruler "在右下角显示当前行信息
set incsearch "搜索加强
set hlsearch "搜索高亮
set guioptions-=T "一出工具栏
set showcmd "显示出输入的命令
set guifont=Menlo:h18 "字体和大小
set lines=45
set columns=100
set scrolloff=3 "光标移动到上下两端,保持3行距离
set history=1000 "历史记录条数从20到1000
set autowrite "自动保存
set guioptions-=m "隐藏菜单栏
set ignorecase "搜索忽略大小写
filetype plugin indent on "自动检测文件类型并启动相关插件


"自动生成代码设置
map <F2> :call SetTitle()<CR>
func SetTitle()
let l = 0
let l = l + 1 | call setline(l,'/************************************************')
let l = l + 1 | call setline(l,' *Author        :mathon')
let l = l + 1 | call setline(l,' *Created Time  :'.strftime('%c'))
"let l = l + 1 | call setline(l,' *File Name     :'.expand('%c'))
let l = l + 1 | call setline(l,' *题目类型:'))
let l = l + 1 | call setline(l,'*************************************************/')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'#include <cstdio>')
let l = l + 1 | call setline(l,'#include <cstring>')
let l = l + 1 | call setline(l,'#include <iostream>')
let l = l + 1 | call setline(l,'#include <algorithm>')
let l = l + 1 | call setline(l,'#include <vector>')
let l = l + 1 | call setline(l,'#include <queue>')
let l = l + 1 | call setline(l,'#include <set>')
let l = l + 1 | call setline(l,'#include <map>')
let l = l + 1 | call setline(l,'#include <string>')
let l = l + 1 | call setline(l,'#include <cmath>')
let l = l + 1 | call setline(l,'#include <cstdlib>')
let l = l + 1 | call setline(l,'#include <ctime>')
let l = l + 1 | call setline(l,'#include <stack>')
let l = l + 1 | call setline(l,'using namespace std;')
let l = l + 1 | call setline(l,'typedef pair<int, int> pii;')
let l = l + 1 | call setline(l,'typedef long long ll;')
let l = l + 1 | call setline(l,'typedef unsigned long long ull;')
let l = l + 1 | call setline(l,'vector<int> vi;')
let l = l + 1 | call setline(l,'#define xx first')
let l = l + 1 | call setline(l,'#define yy second')
let l = l + 1 | call setline(l,'#define sa(n) scanf("%d", &(n))')
let l = l + 1 | call setline(l,'#define rep(i, a, n) for (int i = a; i < n; i++)')
let l = l + 1 | call setline(l,'#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) ')
let l = l + 1 | call setline(l,'#define pr(x) cout << #x << " " << x << " "')
let l = l + 1 | call setline(l,'#define prln(x) cout << #x << " " << x << endl')
let l = l + 1 | call setline(l,'const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 1e5 + 12;')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'int main(void)')
let l = l + 1 | call setline(l,'{')
let l = l + 1 | call setline(l,'#ifdef LOCAL')
let l = l + 1 | call setline(l,'    //freopen("in.txt", "r", stdin);')
let l = l + 1 | call setline(l,'    //freopen("out.txt", "w", stdout);')
let l = l + 1 | call setline(l,'#endif')
let l = l + 1 | call setline(l,'    ')
let l = l + 1 | call setline(l,'    return 0;')
let l = l + 1 | call setline(l,'}')
endfunc

"the cpp f5 run program
map <F5> :call CompileRunGcc()<CR>
func! CompileRunGcc()
        exec "w"
        if &filetype == 'c'
           exec "!g++ -Wall -DLOCAL % -o  %<"
           exec "!time ./%<"
        elseif &filetype == 'cpp'
           exec "!g++ -WALL -DLOCAL % -o  %<"
           exec "!time ./%<"
        elseif &filetype == 'java'
           exec "!javac %"
           exec "!time java %<"
        elseif &filetype == 'sh'
           :!time bash %
        elseif &filetype == 'python'
        exec "!time python3.5 %"
        endif
endfunc

"inoremap ( ()<ESC>i
"inoremap [ []<ESC>i
"inoremap { {<CR><CR>}<ESC>ki<tab><tab>
