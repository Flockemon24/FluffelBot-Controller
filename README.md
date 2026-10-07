# FluffelBot-Controller

<img width="1062" height="691" alt="PCB" src="https://github.com/user-attachments/assets/c4da8110-58db-4df0-92a0-66df966e7f45" />

<img width="486" height="497" alt="image" src="https://github.com/user-attachments/assets/9ce6a67a-737f-4943-b207-b3380b9a0dc1" />

The FluffelBot-Controller PCB is a simple Motorcontroller with an ESP32 and two TB6612FNG to control four wheels.

## Why I built this
I built the FluffelBot-Controller as a part of a school project, in which I'm building a robot called 'FluffelBot'
The bot needs a motor control system, so I designed this PCB and submitted it on 'Half a Life' too.

## How it works
<img width="2203" height="1518" alt="Schematics" src="https://github.com/user-attachments/assets/e9ca0a99-467e-44cd-80c7-794f88acedf8" />

The FluffelBot-Controller uses an ESP32 as the main computer. The ESP32 controls two Dual Motor Driver so the PCB can controll up to four motors indipendently.
For power supply use a 12V-Battery. The controller has a built-in battery protection.

## BoM
| Part | What it's for | Qty | Unit | Total | Vendor |
| --- | --- | --- | --- | --- | --- |
| [ESP32-DEVKITC-32UE](https://www.lcsc.com/product-detail/C20547324.html) | Main Controller | 1 | $9.52 | $9.52 | [LCSC](https://www.lcsc.com/product-detail/C20547324.html) |
| [TB6612FNG](https://www.amazon.com/DIANN-TB6612FNG-Stepper-Driver-Module/dp/B0BLRSWTLM/ref=sr_1_3?crid=3M6QF3UXG9QPJ&dib=eyJ2IjoiMSJ9.N5jurfQZO1h0LeN_cJJnlxDsWv7Lpa1qwfaqbvCa1S9uaLxoEE3YXhWC4-eYVqp0GeN5zweQLT90tK6KvavI4V4kmLeJwKKZ5hGt-_DM5w346QgJfYbqMJIpaX3m-pQ4528uOuVRRkPj6QrbXzsV4pWz1Z5i77YGXcKZex5H0Ot601Gut3WO02foMxQCG07dNo0LHESS6LaXyFBgjktTjx61_COulTxP8tgCX5Wxhew.ilJypxq93LuGaEJZE41cw913tL8_qozMCFqsy83VsvI&dib_tag=se&keywords=TB6612FNG&qid=1791301908&sprefix=tb6612fng+%2Caps%2C258&sr=8-3) | 3x Motor Driver | 1 | $7.82 | $7.82 | [Amazon](https://www.amazon.com/DIANN-TB6612FNG-Stepper-Driver-Module/dp/B0BLRSWTLM/ref=sr_1_3?crid=3M6QF3UXG9QPJ&dib=eyJ2IjoiMSJ9.N5jurfQZO1h0LeN_cJJnlxDsWv7Lpa1qwfaqbvCa1S9uaLxoEE3YXhWC4-eYVqp0GeN5zweQLT90tK6KvavI4V4kmLeJwKKZ5hGt-_DM5w346QgJfYbqMJIpaX3m-pQ4528uOuVRRkPj6QrbXzsV4pWz1Z5i77YGXcKZex5H0Ot601Gut3WO02foMxQCG07dNo0LHESS6LaXyFBgjktTjx61_COulTxP8tgCX5Wxhew.ilJypxq93LuGaEJZE41cw913tL8_qozMCFqsy83VsvI&dib_tag=se&keywords=TB6612FNG&qid=1791301908&sprefix=tb6612fng+%2Caps%2C258&sr=8-3) |
| [BMI160](https://www.amazon.com/Accelerometer-Gyroscope-inertial-Measurement-Sensors/dp/B07VT25PHX/ref=sr_1_1?crid=21RB2BV2WMTZ9&dib=eyJ2IjoiMSJ9.ZcMGEbOziAlWsDIVvtPTZNOFQ1xHVMww2pNwOd2kafk.pKEg9NVhL_18ujxoZMMn_CziFOP-f4w8xGVrMurHQVU&dib_tag=se&keywords=BMI160+1pcs&qid=1791301992&refinements=p_36%3A-400&rnid=386419011&sprefix=bmi160+1pcs%2Caps%2C214&sr=8-1) | IMU Sensor | 1 | $2.82 | $2.82 | [Amazon](https://www.amazon.com/Accelerometer-Gyroscope-inertial-Measurement-Sensors/dp/B07VT25PHX/ref=sr_1_1?crid=21RB2BV2WMTZ9&dib=eyJ2IjoiMSJ9.ZcMGEbOziAlWsDIVvtPTZNOFQ1xHVMww2pNwOd2kafk.pKEg9NVhL_18ujxoZMMn_CziFOP-f4w8xGVrMurHQVU&dib_tag=se&keywords=BMI160+1pcs&qid=1791301992&refinements=p_36%3A-400&rnid=386419011&sprefix=bmi160+1pcs%2Caps%2C214&sr=8-1) |
| [MINI560](https://www.amazon.com/jojnsha-Mini560-Efficient-Indicators-Protection/dp/B0FF94HLZV/ref=sr_1_4_sspa?crid=ISIX4SVOWNL1&dib=eyJ2IjoiMSJ9.AfYm_aQdwkNWh5bYRrGKz3um4yijA83MuOXMZDQqi7c.OpBSQDiQCWpglqKDpyKoVzJyRvxe_YcMJTIJ3jKoSFw&dib_tag=se&keywords=MINI560&qid=1791302054&refinements=p_36%3A-500&rnid=2421879011&sprefix=mini560%2Caps%2C249&sr=8-4-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9tdGY&th=1) | Battery Protection | 1 | $4.99 | $4.99 | [Amazon](https://www.amazon.com/jojnsha-Mini560-Efficient-Indicators-Protection/dp/B0FF94HLZV/ref=sr_1_4_sspa?crid=ISIX4SVOWNL1&dib=eyJ2IjoiMSJ9.AfYm_aQdwkNWh5bYRrGKz3um4yijA83MuOXMZDQqi7c.OpBSQDiQCWpglqKDpyKoVzJyRvxe_YcMJTIJ3jKoSFw&dib_tag=se&keywords=MINI560&qid=1791302054&refinements=p_36%3A-500&rnid=2421879011&sprefix=mini560%2Caps%2C249&sr=8-4-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9tdGY&th=1) |
| **Parts subtotal** | — | — | — | **$25.15** | — |
| **Tax & shipping** | — | — | — | **$4.00** | — |
| **Total** | — | — | — | **$29.15** | — |

Also see the BOM.md file!

## LICENCE
This Project is completely open-source. Feel free to rebuild everything in here.
