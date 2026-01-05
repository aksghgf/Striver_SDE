@echo off
cd /d "%~dp0"
python dsa_automation.py >> automation_log.txt 2>&1
