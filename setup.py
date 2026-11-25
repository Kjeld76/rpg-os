"""
Setup-Skript für RPG-OS
"""

from setuptools import setup, find_packages

setup(
    name="rpg-os",
    version="0.1.0",
    packages=find_packages(),
    install_requires=[],
    entry_points={
        "console_scripts": [
            "rpg-os=src.shell.main:main",
        ],
    },
    python_requires=">=3.11",
)
