import tkinter as tk
from tkinter import filedialog, messagebox
import os

def choose_folder():
    folder = filedialog.askdirectory()
    folder_path.set(folder)

def download():
    url = url_entry.get()
    folder = folder_path.get()

    if not url or not folder:
        messagebox.showerror("Error", "Link and Folder required!")
        return

    command = f'python3 -m yt_dlp -f "bestvideo+bestaudio/best" --merge-output-format mp4 -o "{folder}/%(title)s.%(ext)s" "{url}"'
    
    os.system(command)
    messagebox.showinfo("Done", "Download started/completed!")

# Window
root = tk.Tk()
root.title("YouTube Downloader")
root.geometry("400x200")

folder_path = tk.StringVar()

# URL
tk.Label(root, text="YouTube Link").pack()
url_entry = tk.Entry(root, width=50)
url_entry.pack()

# Folder
tk.Label(root, text="Download Folder").pack()
tk.Entry(root, textvariable=folder_path, width=50).pack()
tk.Button(root, text="Choose Folder", command=choose_folder).pack()

# Download Button
tk.Button(root, text="Download", bg="green", fg="white", command=download).pack(pady=10)

root.mainloop()