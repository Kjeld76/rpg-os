"""
RPG-OS Utils
Hilfsfunktionen
"""

from typing import Any


def format_xp(xp: int) -> str:
    """Formatiert XP als String"""
    if xp >= 1000000:
        return f"{xp/1000000:.1f}M"
    elif xp >= 1000:
        return f"{xp/1000:.1f}k"
    return str(xp)


def format_percentage(value: float) -> str:
    """Formatiert als Prozent"""
    return f"{value*100:.0f}%"


def clamp(value: float, min_val: float, max_val: float) -> float:
    """Begrenzt Wert auf Range"""
    return max(min_val, min(max_val, value))


def get_stat_display(stats: dict[str, Any]) -> str:
    """Erstellt Display für Stats"""
    return " | ".join(f"{k}: {v}" for k, v in stats.items())
