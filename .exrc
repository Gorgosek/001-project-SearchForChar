let s:cpo_save=&cpo
set cpo&vim
cnoremap <silent> <C-R> <Cmd>lua require("which-key").show("\18", {mode = "c", auto = true})
inoremap <silent> <C-R> <Cmd>lua require("which-key").show("\18", {mode = "i", auto = true})
inoremap <C-L> <Right>
inoremap <C-B> ^i
inoremap <C-K> <Up>
inoremap <C-H> <Left>
inoremap <C-J> <Down>
inoremap <C-W> u
inoremap <C-U> u
nnoremap  <Cmd> %y+ 
nnoremap  h
nnoremap <NL> j
nnoremap  k
nnoremap  l
nnoremap  <Cmd> NvimTreeToggle 
nnoremap  <Cmd> w 
nnoremap <silent> Þ <Nop>
nnoremap <silent>  <Cmd>lua require("which-key").show("\23", {mode = "n", auto = true})
tnoremap  
nnoremap  :noh 
nnoremap <silent>  fÞ <Nop>
nnoremap <silent>  cÞ <Nop>
nnoremap <silent>  wÞ <Nop>
nnoremap <silent>  gÞ <Nop>
nnoremap <silent>  mÞ <Nop>
nnoremap <silent>  pÞ <Nop>
nnoremap <silent>  tÞ <Nop>
nnoremap <silent>  rÞ <Nop>
nnoremap <silent>  Þ <Nop>
nnoremap <silent>   <Cmd>lua require("which-key").show(" ", {mode = "n", auto = true})
xnoremap <silent>  Þ <Nop>
xnoremap <silent>   <Cmd>lua require("which-key").show(" ", {mode = "v", auto = true})
nnoremap  e <Cmd> NvimTreeFocus 
nnoremap  ff <Cmd> Telescope find_files 
nnoremap  fo <Cmd> Telescope oldfiles 
nnoremap  pt <Cmd> Telescope terms 
nnoremap  gt <Cmd> Telescope git_status 
nnoremap  fh <Cmd> Telescope help_tags 
nnoremap  th <Cmd> Telescope themes 
nnoremap  cm <Cmd> Telescope git_commits 
nnoremap  fb <Cmd> Telescope buffers 
nnoremap  ma <Cmd> Telescope marks 
nnoremap  fw <Cmd> Telescope live_grep 
nnoremap  fa <Cmd> Telescope find_files follow=true no_ignore=true hidden=true 
nnoremap  fz <Cmd> Telescope current_buffer_fuzzy_find 
vnoremap  / <Cmd>lua require('Comment.api').toggle.linewise(vim.fn.visualmode())
nnoremap  ch <Cmd> NvCheatsheet 
nnoremap  b <Cmd> enew 
nnoremap  rn <Cmd> set rnu! 
nnoremap  n <Cmd> set nu! 
nnoremap <silent> !aÞ <Nop>
nnoremap <silent> !iÞ <Nop>
nnoremap <silent> !Þ <Nop>
nnoremap <silent> ! <Cmd>lua require("which-key").show("!", {mode = "n", auto = true})
nnoremap <silent> " <Cmd>lua require("which-key").show("\"", {mode = "n", auto = true})
xnoremap <silent> " <Cmd>lua require("which-key").show("\"", {mode = "v", auto = true})
xnoremap # y?\V"
nnoremap & :&&
nnoremap <silent> ' <Cmd>lua require("which-key").show("'", {mode = "n", auto = true})
xnoremap * y/\V"
nnoremap <nowait> ; :
nnoremap <silent> <aÞ <Nop>
nnoremap <silent> <iÞ <Nop>
nnoremap <silent> <Þ <Nop>
nnoremap <silent> < <Cmd>lua require("which-key").show("<", {mode = "n", auto = true})
vnoremap < <gv
nnoremap <silent> >aÞ <Nop>
nnoremap <silent> >iÞ <Nop>
nnoremap <silent> >Þ <Nop>
nnoremap <silent> > <Cmd>lua require("which-key").show(">", {mode = "n", auto = true})
vnoremap > >gv
nnoremap Y y$
nnoremap <silent> [Þ <Nop>
nnoremap <silent> [ <Cmd>lua require("which-key").show("[", {mode = "n", auto = true})
nnoremap <silent> ]Þ <Nop>
nnoremap <silent> ] <Cmd>lua require("which-key").show("]", {mode = "n", auto = true})
nnoremap <silent> ` <Cmd>lua require("which-key").show("`", {mode = "n", auto = true})
nnoremap <silent> cÞ <Nop>
nnoremap <silent> c <Cmd>lua require("which-key").show("c", {mode = "n", auto = true})
nnoremap <silent> ciÞ <Nop>
nnoremap <silent> ci <Cmd>lua require("which-key").show("ci", {mode = "n", auto = true})
nnoremap <silent> caÞ <Nop>
nnoremap <silent> dÞ <Nop>
nnoremap <silent> d <Cmd>lua require("which-key").show("d", {mode = "n", auto = true})
nnoremap <silent> daÞ <Nop>
nnoremap <silent> diÞ <Nop>
nnoremap <silent> gÞ <Nop>
nnoremap <silent> g <Cmd>lua require("which-key").show("g", {mode = "n", auto = true})
nnoremap <silent> g~aÞ <Nop>
nnoremap <silent> g~iÞ <Nop>
nnoremap <silent> g~Þ <Nop>
nnoremap <silent> guaÞ <Nop>
nnoremap <silent> guiÞ <Nop>
nnoremap <silent> guÞ <Nop>
nnoremap <silent> gUaÞ <Nop>
nnoremap <silent> gUiÞ <Nop>
nnoremap <silent> gUÞ <Nop>
xnoremap <silent> gÞ <Nop>
xnoremap <silent> g <Cmd>lua require("which-key").show("g", {mode = "v", auto = true})
xnoremap <expr> j v:count || mode(1)[0:1] == "no" ? "j" : "gj"
nnoremap <expr> j v:count || mode(1)[0:1] == "no" ? "j" : "gj"
xnoremap <expr> k v:count || mode(1)[0:1] == "no" ? "k" : "gk"
nnoremap <expr> k v:count || mode(1)[0:1] == "no" ? "k" : "gk"
xnoremap <silent> p p:let @+=@0:let @"=@0
nnoremap <silent> vaÞ <Nop>
nnoremap <silent> viÞ <Nop>
nnoremap <silent> vÞ <Nop>
nnoremap <silent> v <Cmd>lua require("which-key").show("v", {mode = "n", auto = true})
nnoremap <silent> yaÞ <Nop>
nnoremap <silent> yiÞ <Nop>
nnoremap <silent> yÞ <Nop>
nnoremap <silent> y <Cmd>lua require("which-key").show("y", {mode = "n", auto = true})
nnoremap <silent> zfaÞ <Nop>
nnoremap <silent> zfiÞ <Nop>
nnoremap <silent> zfÞ <Nop>
nnoremap <silent> zÞ <Nop>
nnoremap <silent> z <Cmd>lua require("which-key").show("z", {mode = "n", auto = true})
nnoremap <silent> <C-W>Þ <Nop>
nnoremap <silent> <C-W> <Cmd>lua require("which-key").show("\23", {mode = "n", auto = true})
nnoremap <Plug>PlenaryTestFile :lua require('plenary.test_harness').test_file(vim.fn.expand("%:p"))
nnoremap <C-N> <Cmd> NvimTreeToggle 
tnoremap <C-X> 
nnoremap <C-S> <Cmd> w 
nnoremap <C-H> h
nnoremap <C-C> <Cmd> %y+ 
nnoremap <expr> <Up> v:count || mode(1)[0:1] == "no" ? "k" : "gk"
nnoremap <C-K> k
nnoremap <expr> <Down> v:count || mode(1)[0:1] == "no" ? "j" : "gj"
nnoremap <C-J> j
vnoremap <expr> <Down> v:count || mode(1)[0:1] == "no" ? "j" : "gj"
vnoremap <expr> <Up> v:count || mode(1)[0:1] == "no" ? "k" : "gk"
nnoremap <C-L> l
inoremap  ^i
inoremap  <Left>
inoremap <NL> <Down>
inoremap  <Up>
inoremap  <Right>
cnoremap <silent>  <Cmd>lua require("which-key").show("\18", {mode = "c", auto = true})
inoremap <silent>  <Cmd>lua require("which-key").show("\18", {mode = "i", auto = true})
inoremap  u
inoremap  u
let &cpo=s:cpo_save
unlet s:cpo_save
set clipboard=unnamedplus
set expandtab
set fillchars=eob:\ 
set helplang=en
set nohlsearch
set ignorecase
set laststatus=3
set noloadplugins
set mouse=a
set packpath=/squashfs-root/usr/share/nvim/runtime
set noruler
set runtimepath=~/.config/nvim,~/.local/share/nvim/lazy/lazy.nvim,~/.local/share/nvim/lazy/which-key.nvim,~/.local/share/nvim/lazy/better-escape.nvim,~/.local/share/nvim/lazy/cmp-path,~/.local/share/nvim/lazy/cmp-buffer,~/.local/share/nvim/lazy/cmp-nvim-lsp,~/.local/share/nvim/lazy/cmp-nvim-lua,~/.local/share/nvim/lazy/cmp_luasnip,~/.local/share/nvim/lazy/nvim-autopairs,~/.local/share/nvim/lazy/friendly-snippets,~/.local/share/nvim/lazy/LuaSnip,~/.local/share/nvim/lazy/nvim-cmp,~/.local/share/nvim/lazy/gitsigns.nvim,~/.local/share/nvim/lazy/plenary.nvim,~/.local/share/nvim/lazy/nvim-tree.lua,~/.local/share/nvim/lazy/null-ls.nvim,~/.local/share/nvim/lazy/nvim-lspconfig,~/.local/share/nvim/lazy/indent-blankline.nvim,~/.local/share/nvim/lazy/nvim-colorizer.lua,~/.local/share/nvim/lazy/nvim-web-devicons,~/.local/share/nvim/lazy/nvim-treesitter,~/.local/share/nvim/lazy/ui,/squashfs-root/usr/share/nvim/runtime,/squashfs-root/usr/lib/nvim,~/.local/state/nvim/lazy/readme,~/.local/share/nvim/lazy/cmp-path/after,~/.local/share/nvim/lazy/cmp-buffer/after,~/.local/share/nvim/lazy/cmp-nvim-lsp/after,~/.local/share/nvim/lazy/cmp-nvim-lua/after,~/.local/share/nvim/lazy/cmp_luasnip/after
set scrolloff=8
set shiftwidth=4
set shortmess=itFoslnxOITf
set noshowmode
set showtabline=2
set smartcase
set smartindent
set softtabstop=4
set splitbelow
set splitright
set statusline=%!v:lua.require('nvchad.statusline.default').run()
set tabline=%!v:lua.require('nvchad.tabufline.modules').run()
set tabstop=4
set termguicolors
set timeoutlen=400
set undofile
set updatetime=250
set whichwrap=<>[]hl,b,s
set window=51
" vim: set ft=vim :
