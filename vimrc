"<C-a> copy all to system register
map <C-a> gg"+yG
" 显示行号
set nu
set cursorline
" nerdTree快捷键
map <C-e> :NERDTreeToggle<CR>
"自动生成代码设置
map <F2> :call LoadTemplate()<CR>
func LoadTemplate()
	exec "r ~/.vim/templates/main.cpp"
endfunc

"C++ 按F5编译运行
map <F5> :call CompileRunGcc()<CR>
func! CompileRunGcc()
	exec "w"
	if &filetype == 'c'
		exec "!g++ % -g -o %< -O2 -Wall -DMATHON -std=c++11"
		exec "!time ./%<"
	elseif &filetype == 'cpp'
		exec "!g++ % -g -o %< -O2 -Wall -DMATHON -std=c++11"
		exec "!time ./%<"
	elseif &filetype == 'java' 
		exec "!javac %" 
		exec "!time java %<"
	elseif &filetype == 'sh'
		:!time bash %
	elseif &filetype == 'python'
		exec "!time python %"
    elseif &filetype == 'html'
        exec "!firefox % &"
    elseif &filetype == 'go'
        exec "!go build %<"
        exec "!time go run %"
    elseif &filetype == 'mkd'
        exec "!~/.vim/markdown.pl % > %.html &"
        exec "!firefox %.html &"
	endif
endfunc
"C,C++的调试
map <F8> :call Rungdb()<CR>
func! Rungdb()
	exec "w"
	exec "!g++ % -o %< -O2 -Wall -DMATHON -g -std=c++11"
	exec "!lldb %<"
endfunc

"Sets how many lines of history VIM has to remember
set history=500

" Enable filetype plugins
filetype plugin on
filetype indent on

"Set to auto read when a file is changed from the outside
set autoread

" Ignore case when searching
set ignorecase

" When searching try to be smart about case
set smartcase

" Highlight search results
set hlsearch

" Show matching brackets when text indicator is over them
set showmatch
" How many tenths of a second to blink when matching brackets
set mat=2
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Colors and Fonts
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Enable syntax highlighting
let python_highlight_all=1
syntax enable 

try
    colorscheme desert
catch
endtry

set background=dark

" Set extra options when running in GUI mode
if has("gui_running")
    colorscheme solarized
    set term=linux
    " set backspace=2
    set guifont=Source_Code_Pro_Light:h14
    set guioptions-=T
    set guioptions-=e
    set t_Co=256
    set guitablabel=%M\ %t
endif

" Set utf8 as standard encoding and en_US as the standard language
set encoding=utf8

" Use Unix as the standard file type
set ffs=unix,dos,mac

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Text, tab and indent related
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Use spaces instead of tabs
set expandtab

" Be smart when using tabs ;)
set smarttab

" 1 tab == 4 spaces
set shiftwidth=4
set tabstop=4

" Linebreak on 500 characters
set lbr
set tw=500

set ai "Auto indent
set si "Smart indent
set wrap "Wrap lines

" Smart way to move between windows
map <C-j> <C-w>j
map <C-k> <C-W>k
map <C-h> <C-W>h
map <C-l> <C-W>l

" Enable mouse
set mouse=a

" Enable folding
set foldmethod=indent
set foldlevel=99
set backspace=indent,eol,start
" Enable folding with the spacebar
" nnoremap <space> za

"记住最后一次编辑的位置
autocmd BufReadPost *
            \ if line("'\"") > 1 && line("'\"") <= line("$") |
            \   exe "normal! g`\"" |
            \ endif

let g:NERDSpaceDelims=1

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Vundle Raletive 
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
set nocompatible              " be iMproved, required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'
Plugin 'Valloric/YouCompleteMe'
Plugin 'vim-scripts/indentpython.vim'
Plugin 'scrooloose/nerdtree'
Plugin 'artur-shaik/vim-javacomplete2'
Plugin 'scrooloose/nerdcommenter'
Plugin 'SirVer/ultisnips'
"Plugin 'Raimondi/delimitMte'
" The following are examples of different formats supported.
" Keep Plugin commands between vundle#begin/end.

" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line

""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"=> YouCompleteMe
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
set completeopt=longest,menu "让Vim的补全菜单行为与一般IDE一致(参考VimTip1228)
autocmd InsertLeave * if pumvisible() == 0|pclose|endif	"离开插入模式后自动关闭预览窗口
let g:ycm_collect_identifiers_from_tags_files=1	" 开启 YCM 基于标签引擎
let g:ycm_min_num_of_chars_for_completion=2	" 从第2个键入字符就开始罗列匹配项

let g:ycm_cache_omnifunc=0	" 禁止缓存匹配项,每次都重新生成匹配项
let g:ycm_seed_identifiers_with_syntax=1	" 语法关键字补全
nnoremap <F6> :YcmForceCompileAndDiagnostics<CR>	"force recomile with syntastic
"在注释输入中也能补全
let g:ycm_complete_in_comments = 1
"在字符串输入中也能补全
let g:ycm_complete_in_strings = 1
"注释和字符串中的文字也会被收入补全
let g:ycm_collect_identifiers_from_comments_and_strings = 0

nnoremap <leader>jd :YcmCompleter GoToDefinitionElseDeclaration<CR> " 跳转到定义处

let g:ycm_python_binary_path = 'python'
let g:ycm_min_num_of_chars_for_completion = 1
let g:ycm_global_ycm_extra_conf = '~/.ycm_extra_conf.py'

