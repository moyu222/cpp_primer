; Emacs-style cursor movement using Alt (Global)
; 使用 $ 前缀防止修饰键冲突，支持连续输入
; -------------------------------------------------

; 基本光标移动
$!n::
    Send {Down}
    return

$!p::
    Send {Up}
    return

$!f::
    Send {Right}
    return

$!b::
    Send {Left}
    return

$!a::
    Send {Home}
    return

$!e::
    Send {End}
    return

; 删除操作
$!k::
    Send +{End}
    Send {Delete}
    return

$!d::
    Send {Delete}
    return

$!h::
    Send {Backspace}
    return

$!u::
    Send +{Home}
    Send {Delete}
    return

$!Backspace::
    Send ^{Backspace}
    return

$!Delete::
    Send ^{Delete}
    return

; 撤销/重做
$!/::
    Send ^z
    return

$!y::
    Send ^y
    return

; 复制/粘贴/剪切
$!c::
    Send ^c
    return

$!v::
    Send ^v
    return

$!x::
    Send ^x
    return

$!w::
    Send +{Home}
    Send ^c
    return

; 替换
$!r::
    Send ^h
    return

; 带选择的光标移动
$!+n::
    Send +{Down}
    return

$!+p::
    Send +{Up}
    return

$!+f::
    Send +{Right}
    return

$!+b::
    Send +{Left}
    return

$!+a::
    Send +{Home}
    return

$!+e::
    Send +{End}
    return
