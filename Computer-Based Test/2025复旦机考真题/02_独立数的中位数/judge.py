from hashlib import sha256
from pathlib import Path
import random
import subprocess
import sys

ROOT = Path(__file__).resolve().parent
SRC = ROOT / "main.cpp"
EXE = ROOT / "main.exe"

if "--hidden" in sys.argv:
    subprocess.run([sys.executable, str(ROOT.parent.parent / "hidden_judge.py"), ROOT.name], check=False)
    raise SystemExit


def digest(text):
    return sha256(text.strip().encode()).hexdigest()


def array_case(a, k):
    return f"{len(a)} {k}\n" + " ".join(map(str, a)) + "\n"


rng = random.Random(20250901)
large = [rng.randint(-50, 50) for _ in range(3000)]
PUBLIC = [
    (array_case([1, 2, 2, 3, 4, 4, 5], 4), "ed0b39260024a58722c5f68e88254ee4880c3b512ee3dc6a4a8299474b0023ae"),
    (array_case([7, 7, 7, 7], 3), "951b3a4aa4e061f831ea461782258a59abdfda50c7fead744e985f6a39681e74"),
    (array_case(large, 101), "020a5fafe4f11d48a2a6fcb61cb870d4522a32580c7b3e33f77a0dc013a6847a"),
]


def run_case(data, timeout=3.0):
    try:
        p = subprocess.run([str(EXE)], input=data, text=True, capture_output=True, timeout=timeout)
    except subprocess.TimeoutExpired:
        return "TLE", ""
    if p.returncode != 0:
        return "RE", ""
    return "OK", p.stdout


def main():
    if not SRC.exists():
        print("未找到 main.cpp，请先在本目录创建代码文件。")
        return
    build = subprocess.run(["g++", str(SRC), "-std=c++17", "-O2", "-o", str(EXE)], text=True, capture_output=True)
    if build.returncode:
        print("编译失败：")
        print(build.stderr)
        return
    print("编译成功。公开样例评测：")
    for i, (data, expected_digest) in enumerate(PUBLIC, 1):
        status, out = run_case(data)
        result = "通过" if status == "OK" and digest(out) == expected_digest else status if status != "OK" else "答案错误"
        print(f"样例 {i}: {result}")
    print("仅显示公开样例结果；本脚本不运行、也不显示隐藏评测。")


if __name__ == "__main__":
    main()
