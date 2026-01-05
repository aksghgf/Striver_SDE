import os
import shutil
import subprocess
import random
from datetime import datetime

# Configuration
# Auto-detect repository directory (where this script is located)
REPO_DIR = os.path.dirname(os.path.abspath(__file__))

# You may need to update this path to your actual source directory
SOURCE_DIR = r"C:\Users\kumar\OneDrive\Desktop\Striver-s-SDE-Sheet-Solution-main (2)\Striver-s-SDE-Sheet-Solution-main\Striver-s-SDE-Sheet-Solution-main"
GIT_REMOTE = "https://github.com/aksghgf/Striver_SDE.git"

def git_command(args, cwd=REPO_DIR):
    try:
        # Explicitly setting input=None to prevent hanging if it asks for input
        result = subprocess.run(['git'] + args, cwd=cwd, capture_output=True, text=True, check=True, input="")
        print(f"Git command {' '.join(args)} success: {result.stdout.strip()}")
        return True
    except subprocess.CalledProcessError as e:
        print(f"Git command {' '.join(args)} failed: {e.stderr.strip()}")
        return False

def main():
    if not os.path.exists(REPO_DIR):
        print(f"Repository directory {REPO_DIR} does not exist.")
        return

    # Get list of source files
    try:
        source_files = [f for f in os.listdir(SOURCE_DIR) if os.path.isfile(os.path.join(SOURCE_DIR, f))]
    except FileNotFoundError:
        print(f"Source directory {SOURCE_DIR} not found.")
        return

    # Get list of already pushed files (basenames without extension)
    dest_files = []
    for f in os.listdir(REPO_DIR):
        if f.endswith(".cpp"):
            dest_files.append(f[:-4]) # Remove .cpp
    
    # Find candidates
    candidates = [f for f in source_files if f not in dest_files and f != "README.md"]
    
    if not candidates:
        print("No new files to push.")
        return

    # Pick one file
    file_to_push = random.choice(candidates)
    
    src_path = os.path.join(SOURCE_DIR, file_to_push)
    dest_path = os.path.join(REPO_DIR, f"{file_to_push}.cpp")
    
    print(f"Copying {file_to_push} to {dest_path}...")
    shutil.copy2(src_path, dest_path)
    
    # Git operations
    if git_command(['add', '.']):
        timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        commit_msg = f"Add solution for {file_to_push} - {timestamp}"
        if git_command(['commit', '-m', commit_msg]):
            git_command(['push', 'origin', 'main'])

if __name__ == "__main__":
    main()
