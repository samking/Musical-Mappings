title_prefix := "Pitch Detector: --- | "
StringLen, title_trim_length, title_prefix
;;games require a key press duration.
SetKeyDelay, -1, 10

While true 
{
  ;;forces the title string to be at the start of the title
  SetTitleMatchMode, 1
  WinGetTitle, title, Pitch Detector
  if !title 
  {
    ;;sleeps for one tenth of a second
    Sleep 100
    Continue
  }
  ;;just get the letter
  ;note := SubStr(title, 17, 1)
  key := SubStr(title, title_trim_length + 1)

  ;;for debugging
;  IfWinActive ahk_class Notepad++ 
;  {
;    if key
;    {
;      if key != previousKey
;      {
;        Send {%previousKey% up}
;        Send {%key% down}
;      }
;    }
;    else
;    {
;      if previousKey
;      {
;        Send {%previousKey% up}
;      }
;    }
;  }

  if key
  {
    if key != previousKey
    {
      if previousKey
      {
        Send {%previousKey% up}
      }
      Send {%key% down}
    }
  }
  else
  {
    if previousKey
    {
      Send {%previousKey% up}
    }
  }

  previousKey := key
    
  Sleep 10
}
