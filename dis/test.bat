for %%f in (*.spv*) do (
    SpvGenTwoDisassembler.exe %%f --assignids
    IF %ERRORLEVEL% NEQ 0 (
        pause
    )
)

pause