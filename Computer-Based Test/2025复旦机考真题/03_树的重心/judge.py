from hashlib import sha256
from pathlib import Path
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


def tree_case(n, edges):
    return str(n) + "\n" + "\n".join(f"{u} {v}" for u, v in edges) + ("\n" if edges else "")


PUBLIC = [
    (tree_case(5, [(1, 2), (2, 3), (3, 4), (3, 5)]), "c64b40bd6b04f739d22eede5a843a916f7581a6868d763dccb4137b482233d35"),
    (tree_case(6, [(1, 2), (2, 3), (3, 4), (4, 5), (5, 6)]), "cd0cf807835179d73cad42fefc8c76827617958cf3e022ae2c8c454828e9cc38"),
    (tree_case(2000, [(i, i + 1) for i in range(1, 2000)]), "dcd9ab06901d3f913932062bff17aedd11f5738ecc02e9c43c076b890a9ed9f9"),
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
