from selenium import webdriver
from selenium.webdriver.firefox.options import Options
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

from PIL import Image

import io
import sys
import time
import argparse

DEVICE_PIXEL_RATIO = 2.0

MANUAL_COLUMN_ASPECT_RATIO = 0.358 # estimated by screenshot

parser = argparse.ArgumentParser()
parser.add_argument("-o", "--output")
parser.add_argument("-H", "--host")
parser.add_argument("--crop", action="store_true")
parser.add_argument("-e", "--element", nargs='?')
parser.add_argument("-c", "--click", nargs='*')
parser.add_argument("-f", "--first", nargs='?')
parser.add_argument("-l", "--last", nargs='?')
parser.add_argument("-s", "--style", nargs='?')
parser.add_argument("-w", "--width", nargs='?')

args = parser.parse_args()

print("Screenshotting http://{}/{} to {}".format(args.host, args.element, args.output))

options = Options()
options.add_argument('-headless')
options.set_preference("layout.css.devPixelsPerPx", str(DEVICE_PIXEL_RATIO))

with webdriver.Firefox(options=options) as driver:

    # 992 is just above the md<->lg breakpoint
    driver.set_window_size(args.width if args.width else 992, 10000)
    driver.get('http://' + args.host)

    if args.click:
        for to_click in args.click:
            WebDriverWait(driver, 10).until(EC.element_to_be_clickable((By.CSS_SELECTOR, to_click))).click()

    if args.element:
        # Add padding around element. This fixes cut off borders in the screenshot
        script = 'document.styleSheets[0].insertRule("{} {{padding: 1px;}}", 0 )'.format(args.element)
        driver.execute_script(script)

    if args.style:
        script = 'document.styleSheets[0].insertRule("{}", 0 )'.format(args.style)
        driver.execute_script(script)

    # Await fade transition
    time.sleep(1)

    # Smile!
    element = driver.find_element(By.CSS_SELECTOR, args.element) if args.element else driver.find_element(By.TAG_NAME, "body")
    png = element.screenshot_as_png

    # Crop inserted padding and (if a complete subpage is screenshotted) the header fade.
    image = Image.open(io.BytesIO(png))

    left = 0
    right = left + (image.size[0])

    top = 24 if args.crop else 0
    if args.first:
        top_e = driver.find_element(By.CSS_SELECTOR, args.first)
        top = (top_e.location["y"] - element.location["y"]) * DEVICE_PIXEL_RATIO

    bottom = (image.size[1])

    if args.last:
        bottom_e = driver.find_element(By.CSS_SELECTOR, args.last)
        y = bottom_e.location["y"] - element.location["y"]
        h = bottom_e.size["height"]
        bottom = (y + h) * DEVICE_PIXEL_RATIO

    image = image.crop((left, top, right, bottom))

    if image.size[0] / image.size[1] < MANUAL_COLUMN_ASPECT_RATIO:
        print("WARNING: Screenshot aspect ratio {} too low. Will not fit in one manual column!".format(image.size[0] / image.size[1]))

    image.save(args.output)
