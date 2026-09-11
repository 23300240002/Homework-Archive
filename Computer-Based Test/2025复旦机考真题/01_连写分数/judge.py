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


PUBLIC = [
    ("4 1\n1234\n34\n12\n", "25fc0e7096fc653718202dc30b0c580b8ab87eac11a700cba03a7c021bc35b0c"),
    ("4 2\n0007\n0 7\n0\n", "7902699be42c8a8e46fbbb4501726517e86b22c56a189f7625a6da49081b2451"),
    ("200 4\n" + "1" * 200 + "\n1111 111 11 1\n9999\n", "0db0c9758028d69add302134246a86935647c5c6611e52096780b6f5ab6e1bdc"),
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
