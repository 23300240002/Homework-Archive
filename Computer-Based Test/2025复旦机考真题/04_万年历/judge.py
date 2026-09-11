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


def date_case(queries):
    return str(len(queries)) + "\n" + "\n".join(f"{y} {m} {d}" for y, m, d in queries) + "\n"


PUBLIC = [
    (date_case([(2025, 8, 26), (2025, 8, 25), (2024, 2, 29)]), "1d47d9ac8ca3da65638f5b5e2a42c3597e2e4837d17db7fa68e64b523a2585e8"),
    (date_case([(2000, 2, 29), (1900, 3, 1)]), "f49cd5a701f3812d06d2893e30bb7ec436b5b1c0114269a5904287de18aff08e"),
    (date_case([(2025, m, 1) for m in range(1, 13)]), "6ea04f78b65826f26b7456436e05cbcc91091d7fbdb667470c94b90f7fe5107c"),
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
