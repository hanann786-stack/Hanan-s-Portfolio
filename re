<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <title>Hanan Arif — Conversion Copywriter</title>
  <meta name="description" content="Hanan Arif — Conversion-focused copywriter. The portfolio itself is the proof." />
  <style>
    :root{
      --bg0:#05060a;
      --bg1:#070a12;
      --ink:#EAF0FF;
      --muted:rgba(234,240,255,.72);
      --muted2:rgba(234,240,255,.58);
      --line:rgba(255,255,255,.10);
      --glass:rgba(255,255,255,.06);
      --glass2:rgba(255,255,255,.10);
      --shadow: 0 24px 70px rgba(0,0,0,.55);
      --shadow2: 0 18px 48px rgba(0,0,0,.45);
      --accent:#8AF4FF;
      --accent2:#B6A7FF;
      --accent3:#76FFB8;
      --danger:#FF4D6D;
      --radius: 18px;
      --radius2: 28px;
      --max: 1180px;
      --ease: cubic-bezier(.16,1,.3,1);
      --ease2: cubic-bezier(.2,.9,.2,1);
      --font: ui-sans-serif, system-ui, -apple-system, Segoe UI, Roboto, Helvetica, Arial, "Apple Color Emoji","Segoe UI Emoji";
      --serif: ui-serif, Georgia, Cambria, "Times New Roman", Times, serif;
      --mono: ui-monospace, SFMono-Regular, Menlo, Monaco, Consolas, "Liberation Mono", "Courier New", monospace;
    }

    *{box-sizing:border-box}
    html,body{height:100%}
    body{
      margin:0;
      font-family: var(--font);
      color: var(--ink);
      background: radial-gradient(1400px 900px at 20% 20%, rgba(138,244,255,.10), transparent 60%),
                  radial-gradient(1200px 900px at 80% 20%, rgba(182,167,255,.10), transparent 62%),
                  radial-gradient(1000px 800px at 50% 90%, rgba(118,255,184,.07), transparent 62%),
                  linear-gradient(180deg, var(--bg0), var(--bg1));
      overflow: hidden; /* we drive scroll internally for cinematic inertia */
    }

    /* --- WebGL background canvas --- */
    #bg{
      position: fixed;
      inset: 0;
      z-index: 0;
      width: 100vw;
      height: 100vh;
      display: block;
      background: transparent;
    }

    /* --- Ambient fog/film grain layers --- */
    .film{
      position: fixed;
      inset: 0;
      z-index: 1;
      pointer-events: none;
      background:
        radial-gradient(1200px 900px at 30% 30%, rgba(255,255,255,.04), transparent 60%),
        radial-gradient(900px 700px at 70% 70%, rgba(255,255,255,.03), transparent 65%),
        radial-gradient(900px 700px at 70% 15%, rgba(138,244,255,.04), transparent 60%),
        radial-gradient(900px 700px at 20% 85%, rgba(182,167,255,.035), transparent 58%);
      mix-blend-mode: screen;
      opacity: .8;
      filter: blur(.2px);
    }
    .grain{
      position: fixed;
      inset: -20%;
      z-index: 2;
      pointer-events: none;
      opacity: .12;
      background-image:
        url("data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' width='220' height='220'%3E%3Cfilter id='n'%3E%3CfeTurbulence type='fractalNoise' baseFrequency='.7' numOctaves='3' stitchTiles='stitch'/%3E%3C/filter%3E%3Crect width='220' height='220' filter='url(%23n)' opacity='.65'/%3E%3C/svg%3E");
      background-size: 260px 260px;
      mix-blend-mode: overlay;
      transform: translate3d(0,0,0);
      animation: grainMove 8s linear infinite;
    }
    @keyframes grainMove{
      0%{transform: translate3d(-2%, -2%, 0)}
      25%{transform: translate3d(2%, -3%, 0)}
      50%{transform: translate3d(3%, 2%, 0)}
      75%{transform: translate3d(-3%, 3%, 0)}
      100%{transform: translate3d(-2%, -2%, 0)}
    }

    /* --- Top nav / HUD --- */
    .hud{
      position: fixed;
      top: 14px;
      left: 0;
      right: 0;
      z-index: 30;
      display:flex;
      justify-content:center;
      pointer-events: none;
    }
    .nav{
      width:min(var(--max), calc(100vw - 28px));
      pointer-events: auto;
      display:flex;
      align-items:center;
      justify-content: space-between;
      padding: 10px 12px;
      border-radius: 999px;
      background: linear-gradient(180deg, rgba(255,255,255,.08), rgba(255,255,255,.04));
      border: 1px solid rgba(255,255,255,.10);
      box-shadow: 0 14px 40px rgba(0,0,0,.35);
      backdrop-filter: blur(14px);
      -webkit-backdrop-filter: blur(14px);
      transform: translateZ(0);
    }
    .brand{
      display:flex;
      align-items:center;
      gap: 10px;
      padding: 6px 10px;
      border-radius: 999px;
    }
    .sig{
      width: 34px;
      height: 34px;
      border-radius: 10px;
      background:
        radial-gradient(18px 18px at 30% 30%, rgba(138,244,255,.75), transparent 60%),
        radial-gradient(18px 18px at 70% 70%, rgba(182,167,255,.65), transparent 60%),
        linear-gradient(180deg, rgba(255,255,255,.12), rgba(255,255,255,.06));
      border: 1px solid rgba(255,255,255,.14);
      box-shadow: 0 14px 30px rgba(0,0,0,.35);
      position: relative;
      overflow: hidden;
    }
    .sig:after{
      content:"";
      position:absolute; inset:-80%;
      background: conic-gradient(from 180deg, transparent, rgba(255,255,255,.25), transparent 55%);
      animation: sheen 6.6s linear infinite;
      filter: blur(1px);
      opacity:.75;
    }
    @keyframes sheen{
      0%{transform: translate3d(-20%, -20%,0) rotate(0deg)}
      100%{transform: translate3d(20%, 20%,0) rotate(360deg)}
    }

    .brand .name{
      display:flex; flex-direction:column; line-height: 1.05;
    }
    .brand .name strong{
      font-weight: 650;
      letter-spacing: .2px;
      font-size: 13px;
    }
    .brand .name span{
      font-size: 12px;
      color: var(--muted);
      letter-spacing: .2px;
    }

    .navlinks{
      display:flex; align-items:center; gap: 8px;
    }
    .chip{
      position: relative;
      display:inline-flex;
      align-items:center;
      gap: 8px;
      padding: 9px 12px;
      border-radius: 999px;
      border: 1px solid rgba(255,255,255,.10);
      background: rgba(0,0,0,.18);
      backdrop-filter: blur(10px);
      -webkit-backdrop-filter: blur(10px);
      color: rgba(234,240,255,.92);
      font-size: 12px;
      letter-spacing: .2px;
      text-decoration:none;
      outline: none;
      cursor: pointer;
      transform-style: preserve-3d;
      transition: transform .25s var(--ease), background .25s var(--ease), border-color .25s var(--ease);
      user-select: none;
      will-change: transform;
    }
    .chip:before{
      content:"";
      position:absolute; inset: -1px;
      border-radius: 999px;
      background: radial-gradient(200px 80px at var(--mx, 50%) var(--my, 50%), rgba(138,244,255,.25), transparent 60%),
                  radial-gradient(220px 90px at calc(var(--mx, 50%) + 12%) calc(var(--my, 50%) + 12%), rgba(182,167,255,.20), transparent 62%);
      opacity: 0;
      transition: opacity .25s var(--ease);
      pointer-events:none;
    }
    .chip:hover{
      background: rgba(255,255,255,.06);
      border-color: rgba(255,255,255,.16);
      transform: translate3d(0,-1px,10px);
    }
    .chip:hover:before{opacity:1}
    .chip .dot{
      width: 6px; height: 6px; border-radius: 999px;
      background: linear-gradient(180deg, rgba(138,244,255,1), rgba(182,167,255,1));
      box-shadow: 0 0 0 3px rgba(138,244,255,.12);
    }
    .ctaChip{
      background: linear-gradient(180deg, rgba(138,244,255,.16), rgba(182,167,255,.10));
      border-color: rgba(138,244,255,.22);
    }
    .ctaChip:hover{
      background: linear-gradient(180deg, rgba(138,244,255,.22), rgba(182,167,255,.14));
      transform: translate3d(0,-1px,14px);
    }

    /* --- Scroll container / camera rig --- */
    .stage{
      position: fixed;
      inset: 0;
      z-index: 10;
      overflow: hidden;
      perspective: 1200px;
      perspective-origin: 50% 40%;
    }
    .camera{
      position:absolute;
      inset: 0;
      transform-style: preserve-3d;
      will-change: transform, filter;
      filter: saturate(1.02) contrast(1.02);
    }

    /* Scenes: full viewport each; arranged vertically */
    .scenes{
      position:absolute;
      left: 0;
      top: 0;
      width: 100%;
      transform-style: preserve-3d;
      will-change: transform;
    }

    section.scene{
      position: relative;
      height: 100vh;
      width: 100%;
      display:flex;
      align-items:center;
      justify-content:center;
      padding: 96px 14px 64px;
      transform-style: preserve-3d;
    }

    .wrap{
      width: min(var(--max), 100%);
      margin: 0 auto;
      position: relative;
      transform-style: preserve-3d;
    }

    /* Floating grid / spatial guides */
    .grid3d{
      position:absolute; inset: -10vh -6vw;
      transform: translateZ(-240px);
      opacity: .35;
      background:
        linear-gradient(to right, rgba(255,255,255,.07) 1px, transparent 1px) 0 0 / 64px 64px,
        linear-gradient(to bottom, rgba(255,255,255,.05) 1px, transparent 1px) 0 0 / 64px 64px;
      mask-image: radial-gradient(60% 55% at 50% 45%, rgba(0,0,0,1), rgba(0,0,0,0));
      pointer-events:none;
      filter: blur(.2px);
    }

    /* Title systems */
    .kicker{
      font-size: 12px;
      color: var(--muted);
      letter-spacing: .24em;
      text-transform: uppercase;
      display:inline-flex;
      align-items:center;
      gap: 10px;
      padding: 10px 12px;
      border-radius: 999px;
      border: 1px solid rgba(255,255,255,.10);
      background: rgba(0,0,0,.20);
      backdrop-filter: blur(10px);
      -webkit-backdrop-filter: blur(10px);
      box-shadow: 0 14px 40px rgba(0,0,0,.28);
      transform: translateZ(30px);
    }
    .kicker i{
      font-style: normal;
      width: 10px; height: 10px;
      border-radius: 999px;
      background: radial-gradient(circle at 30% 30%, rgba(138,244,255,1), rgba(182,167,255,1));
      box-shadow: 0 0 0 5px rgba(138,244,255,.10);
    }

    .heroLayout{
      display:grid;
      grid-template-columns: 1.05fr .95fr;
      gap: 22px;
      align-items: center;
      transform-style: preserve-3d;
    }

    .headline{
      transform-style: preserve-3d;
      position: relative;
      padding: 10px 0;
    }
    .h1{
      font-size: clamp(38px, 5.1vw, 78px);
      line-height: .96;
      margin: 14px 0 14px;
      letter-spacing: -0.03em;
      font-weight: 680;
      text-shadow: 0 14px 40px rgba(0,0,0,.55);
    }
    .h1 .line{
      display:block;
      transform-style: preserve-3d;
      will-change: transform;
    }
    .h1 .line:nth-child(1){ transform: translateZ(42px); }
    .h1 .line:nth-child(2){ transform: translateZ(64px); }
    .h1 .line:nth-child(3){ transform: translateZ(46px); }

    .h1 .glow{
      background: linear-gradient(90deg, rgba(138,244,255,1), rgba(182,167,255,1), rgba(118,255,184,1));
      -webkit-background-clip: text;
      background-clip: text;
      color: transparent;
      filter: drop-shadow(0 16px 35px rgba(138,244,255,.12));
    }

    .sub{
      max-width: 44ch;
      margin: 0 0 18px;
      font-size: clamp(14px, 1.5vw, 18px);
      line-height: 1.5;
      color: rgba(234,240,255,.78);
      transform: translateZ(28px);
      text-shadow: 0 12px 28px rgba(0,0,0,.42);
    }

    .heroActions{
      display:flex;
      gap: 12px;
      align-items:center;
      flex-wrap: wrap;
      transform-style: preserve-3d;
      margin-top: 18px;
    }

    .btn{
      position: relative;
      display:inline-flex;
      align-items:center;
      justify-content:center;
      gap: 10px;
      padding: 14px 16px;
      border-radius: 14px;
      border: 1px solid rgba(255,255,255,.12);
      background: rgba(255,255,255,.06);
      color: rgba(234,240,255,.95);
      text-decoration:none;
      font-weight: 620;
      letter-spacing: .2px;
      font-size: 14px;
      cursor:pointer;
      transform-style: preserve-3d;
      transition: transform .22s var(--ease), border-color .22s var(--ease), background .22s var(--ease), box-shadow .22s var(--ease);
      box-shadow: 0 18px 55px rgba(0,0,0,.38);
      backdrop-filter: blur(12px);
      -webkit-backdrop-filter: blur(12px);
      user-select: none;
      outline: none;
      will-change: transform;
    }
    .btn:before{
      content:"";
      position:absolute;
      inset:-1px;
      border-radius: 14px;
      background:
        radial-gradient(240px 110px at var(--mx, 50%) var(--my, 50%), rgba(138,244,255,.28), transparent 60%),
        radial-gradient(260px 120px at calc(var(--mx, 50%) + 14%) calc(var(--my, 50%) + 10%), rgba(182,167,255,.18), transparent 62%);
      opacity: 0;
      transition: opacity .22s var(--ease);
      pointer-events:none;
    }
    .btn:hover:before{opacity:1}
    .btn:hover{
      transform: translate3d(0,-1px,18px);
      border-color: rgba(255,255,255,.18);
      background: rgba(255,255,255,.075);
      box-shadow: 0 28px 78px rgba(0,0,0,.48);
    }
    .btnPrimary{
      background: linear-gradient(180deg, rgba(138,244,255,.18), rgba(182,167,255,.12));
      border-color: rgba(138,244,255,.22);
    }
    .btnPrimary:hover{
      background: linear-gradient(180deg, rgba(138,244,255,.24), rgba(182,167,255,.16));
      border-color: rgba(138,244,255,.30);
    }
    .btnGhost{
      background: rgba(0,0,0,.20);
      border-color: rgba(255,255,255,.10);
      color: rgba(234,240,255,.86);
    }

    .micro{
      margin-top: 12px;
      color: rgba(234,240,255,.60);
      font-size: 12px;
      letter-spacing: .2px;
      transform: translateZ(18px);
    }
    .micro b{color: rgba(234,240,255,.82); font-weight: 650}

    /* --- Right hero object (3D slab) --- */
    .heroObj{
      position: relative;
      transform-style: preserve-3d;
      height: min(430px, 54vh);
      min-height: 330px;
    }
    .slab{
      position:absolute;
      inset: 0;
      border-radius: var(--radius2);
      background: linear-gradient(180deg, rgba(255,255,255,.08), rgba(255,255,255,.03));
      border: 1px solid rgba(255,255,255,.12);
      box-shadow: var(--shadow);
      backdrop-filter: blur(18px);
      -webkit-backdrop-filter: blur(18px);
      transform: translateZ(40px) rotateX(5deg) rotateY(-8deg);
      transform-origin: 50% 50%;
      overflow:hidden;
    }
    .slab:before{
      content:"";
      position:absolute; inset:0;
      background:
        radial-gradient(700px 450px at 10% 20%, rgba(138,244,255,.22), transparent 60%),
        radial-gradient(600px 420px at 90% 15%, rgba(182,167,255,.20), transparent 60%),
        radial-gradient(680px 520px at 60% 95%, rgba(118,255,184,.12), transparent 62%),
        linear-gradient(180deg, rgba(0,0,0,.05), rgba(0,0,0,.22));
      opacity: .9;
      pointer-events:none;
    }
    .slab:after{
      content:"";
      position:absolute; inset:-30%;
      background: conic-gradient(from 220deg, rgba(255,255,255,0), rgba(255,255,255,.18), rgba(255,255,255,0) 52%);
      transform: translate3d(-12%, -10%, 0) rotate(10deg);
      opacity:.55;
      filter: blur(1px);
      animation: slabSheen 7.6s var(--ease) infinite;
    }
    @keyframes slabSheen{
      0%{transform: translate3d(-12%, -10%, 0) rotate(10deg)}
      50%{transform: translate3d(8%, 6%, 0) rotate(18deg)}
      100%{transform: translate3d(-12%, -10%, 0) rotate(10deg)}
    }

    .slabInner{
      position:absolute; inset: 0;
      padding: 18px;
      display:flex;
      flex-direction:column;
      justify-content: space-between;
      transform-style: preserve-3d;
    }
    .slabTop{
      display:flex; align-items:center; justify-content: space-between;
      transform: translateZ(26px);
    }
    .pill{
      font-size: 12px;
      color: rgba(234,240,255,.82);
      padding: 9px 10px;
      border-radius: 999px;
      border: 1px solid rgba(255,255,255,.12);
      background: rgba(0,0,0,.18);
      backdrop-filter: blur(10px);
      -webkit-backdrop-filter: blur(10px);
      display:inline-flex; gap: 8px; align-items:center;
    }
    .pill .bar{
      width: 10px; height: 10px; border-radius: 3px;
      background: linear-gradient(180deg, rgba(138,244,255,1), rgba(182,167,255,1));
      box-shadow: 0 0 0 4px rgba(138,244,255,.10);
    }
    .metrics{
      display:grid;
      grid-template-columns: 1fr 1fr;
      gap: 10px;
      transform: translateZ(22px);
      margin-top: 10px;
    }
    .metric{
      border-radius: 16px;
      border: 1px solid rgba(255,255,255,.10);
      background: rgba(255,255,255,.05);
      padding: 12px 12px 10px;
      box-shadow: 0 18px 48px rgba(0,0,0,.28);
      transform-style: preserve-3d;
      position:relative;
      overflow:hidden;
    }
    .metric:before{
      content:"";
      position:absolute; inset:-1px;
      background: radial-gradient(240px 120px at 20% 0%, rgba(138,244,255,.18), transparent 60%),
                  radial-gradient(240px 120px at 100% 80%, rgba(182,167,255,.14), transparent 60%);
      opacity:.6;
      pointer-events:none;
    }
    .metric strong{
      display:block;
      font-size: 18px;
      letter-spacing: -0.02em;
      transform: translateZ(14px);
    }
    .metric span{
      display:block;
      margin-top: 4px;
      font-size: 12px;
      color: rgba(234,240,255,.68);
      transform: translateZ(10px);
    }
    .slabBottom{
      display:flex; flex-direction:column; gap: 10px;
      transform: translateZ(20px);
    }
    .quote{
      border-radius: 18px;
      border: 1px solid rgba(255,255,255,.10);
      background: rgba(0,0,0,.20);
      padding: 14px 14px;
      color: rgba(234,240,255,.86);
      box-shadow: 0 18px 50px rgba(0,0,0,.30);
      position:relative;
      overflow:hidden;
    }
    .quote:before{
      content:"";
      position:absolute; inset:-2px;
      background: radial-gradient(420px 160px at var(--mx, 40%) var(--my, 30%), rgba(118,255,184,.14), transparent 60%);
      opacity:.8;
      pointer-events:none;
    }
    .quote p{margin:0; font-size: 13px; line-height: 1.45}
    .quote b{color: rgba(234,240,255,.96); font-weight: 680}
    .fine{
      font-family: var(--mono);
      font-size: 11px;
      color: rgba(234,240,255,.56);
      letter-spacing: .08em;
      text-transform: uppercase;
    }

    /* --- Scene headings / typography --- */
    .sceneTitle{
      font-size: clamp(26px, 3.4vw, 46px);
      line-height: 1.02;
      letter-spacing: -0.03em;
      margin: 0 0 10px;
      transform-style: preserve-3d;
      text-shadow: 0 14px 40px rgba(0,0,0,.55);
    }
    .sceneTitle .z1{display:block; transform: translateZ(38px)}
    .sceneTitle .z2{display:block; transform: translateZ(54px)}
    .sceneTitle .z3{display:block; transform: translateZ(42px)}
    .sceneLead{
      margin: 0;
      max-width: 66ch;
      color: rgba(234,240,255,.74);
      line-height: 1.6;
      font-size: 15px;
      transform: translateZ(22px);
    }

    /* Authority scene */
    .authority{
      display:grid;
      grid-template-columns: 1.15fr .85fr;
      gap: 18px;
      align-items:center;
      transform-style: preserve-3d;
    }
    .pullQuote{
      border-radius: 26px;
      border: 1px solid rgba(255,255,255,.10);
      background: linear-gradient(180deg, rgba(255,255,255,.07), rgba(255,255,255,.03));
      backdrop-filter: blur(18px);
      -webkit-backdrop-filter: blur(18px);
      box-shadow: var(--shadow2);
      padding: 22px 18px;
      transform: translateZ(36px) rotateY(6deg);
      position:relative;
      overflow:hidden;
    }
    .pullQuote:before{
      content:"";
      position:absolute; inset:-1px;
      background:
        radial-gradient(520px 220px at 15% 10%, rgba(138,244,255,.18), transparent 65%),
        radial-gradient(520px 220px at 90% 90%, rgba(182,167,255,.14), transparent 65%);
      opacity:.9;
      pointer-events:none;
    }
    .stack{
      display:flex;
      flex-direction:column;
      gap: 10px;
      transform-style: preserve-3d;
    }
    .stack .line{
      font-size: clamp(22px, 3.1vw, 42px);
      letter-spacing: -0.03em;
      line-height: 1.02;
      margin: 0;
      transform-style: preserve-3d;
      will-change: transform, opacity;
    }
    .stack .line:nth-child(1){transform: translateZ(58px)}
    .stack .line:nth-child(2){transform: translateZ(78px)}
    .stack .line:nth-child(3){transform: translateZ(62px)}
    .stack .line strong{
      font-weight: 720;
      background: linear-gradient(90deg, rgba(138,244,255,1), rgba(182,167,255,1));
      -webkit-background-clip: text; background-clip: text; color: transparent;
    }

    /* About */
    .about{
      display:grid;
      grid-template-columns: 1fr 1fr;
      gap: 18px;
      align-items: center;
      transform-style: preserve-3d;
    }
    .story{
      border-radius: 28px;
      border: 1px solid rgba(255,255,255,.10);
      background: rgba(255,255,255,.05);
      backdrop-filter: blur(16px);
      -webkit-backdrop-filter: blur(16px);
      box-shadow: var(--shadow2);
      padding: 22px 18px;
      transform: translateZ(34px) rotateY(-6deg);
      position:relative;
      overflow:hidden;
    }
    .story:before{
      content:"";
      position:absolute; inset:-1px;
      background: radial-gradient(520px 240px at 10% 0%, rgba(118,255,184,.12), transparent 65%),
                  radial-gradient(520px 240px at 90% 90%, rgba(138,244,255,.12), transparent 65%);
      opacity:.9;
      pointer-events:none;
    }
    .story p{
      margin: 0 0 10px;
      color: rgba(234,240,255,.76);
      line-height: 1.65;
      font-size: 14.5px;
      transform: translateZ(14px);
      text-shadow: 0 10px 24px rgba(0,0,0,.35);
    }
    .story p:last-child{margin-bottom:0}
    .story b{color: rgba(234,240,255,.92); font-weight: 700}
    .credGrid{
      display:grid;
      gap: 10px;
      transform-style: preserve-3d;
    }
    .cred{
      border-radius: 18px;
      border: 1px solid rgba(255,255,255,.10);
      background: rgba(0,0,0,.22);
      padding: 14px 14px;
      box-shadow: 0 18px 48px rgba(0,0,0,.26);
      transform-style: preserve-3d;
      position:relative;
      overflow:hidden;
    }
    .cred:before{
      content:"";
      position:absolute; inset:-1px;
      background: radial-gradient(420px 180px at var(--mx, 50%) var(--my, 50%), rgba(182,167,255,.14), transparent 62%);
      opacity:.9;
      pointer-events:none;
    }
    .cred strong{
      display:block;
      font-size: 13px;
      letter-spacing: .2px;
      transform: translateZ(14px);
    }
    .cred span{
      display:block;
      margin-top: 6px;
      font-size: 13px;
      color: rgba(234,240,255,.66);
      line-height: 1.45;
      transform: translateZ(10px);
    }

    /* Services cards with thickness */
    .services{
      transform-style: preserve-3d;
    }
    .cards{
      display:grid;
      grid-template-columns: repeat(5, 1fr);
      gap: 12px;
      margin-top: 16px;
      transform-style: preserve-3d;
    }
    .card3d{
      position:relative;
      border-radius: 18px;
      transform-style: preserve-3d;
      cursor:pointer;
      outline:none;
      user-select:none;
    }
    .cardFace{
      position:relative;
      border-radius: 18px;
      border: 1px solid rgba(255,255,255,.10);
      background: linear-gradient(180deg, rgba(255,255,255,.07), rgba(255,255,255,.03));
      backdrop-filter: blur(16px);
      -webkit-backdrop-filter: blur(16px);
      box-shadow: 0 18px 52px rgba(0,0,0,.34);
      padding: 16px 14px;
      min-height: 168px;
      overflow:hidden;
      transform: translateZ(24px);
      transition: transform .25s var(--ease), border-color .25s var(--ease), background .25s var(--ease);
    }
    .card3d:before{
      content:"";
      position:absolute;
      inset: 10px;
      border-radius: 16px;
      background: rgba(0,0,0,.28);
      transform: translateZ(0px);
      filter: blur(10px);
      opacity: .6;
    }
    .card3d:after{
      content:"";
      position:absolute;
      left: 10px; right: 10px; bottom: -12px;
      height: 18px;
      border-radius: 0 0 16px 16px;
      background: linear-gradient(180deg, rgba(0,0,0,.0), rgba(0,0,0,.40));
      transform: translateZ(6px) rotateX(80deg);
      transform-origin: top;
      opacity: .75;
      pointer-events:none;
    }
    .cardFace:before{
      content:"";
      position:absolute; inset:-1px;
      background:
        radial-gradient(340px 160px at var(--mx, 50%) var(--my, 50%), rgba(138,244,255,.22), transparent 60%),
        radial-gradient(340px 160px at calc(var(--mx, 50%) + 18%) calc(var(--my, 50%) + 10%), rgba(182,167,255,.18), transparent 62%);
      opacity: 0;
      transition: opacity .25s var(--ease);
      pointer-events:none;
    }
    .card3d:hover .cardFace:before{opacity:1}
    .card3d:hover .cardFace{
      transform: translateZ(34px);
      border-color: rgba(255,255,255,.16);
      background: linear-gradient(180deg, rgba(255,255,255,.08), rgba(255,255,255,.035));
    }
    .cardTitle{
      font-weight: 700;
      letter-spacing: -.01em;
      margin: 0;
      font-size: 14px;
      transform: translateZ(12px);
    }
    .cardDesc{
      margin: 10px 0 0;
      font-size: 13px;
      line-height: 1.55;
      color: rgba(234,240,255,.68);
      transform: translateZ(10px);
    }
    .cardMore{
      margin-top: 12px;
      display:flex;
      align-items:center;
      justify-content: space-between;
      color: rgba(234,240,255,.64);
      font-size: 12px;
      letter-spacing: .12em;
      text-transform: uppercase;
      transform: translateZ(10px);
    }
    .cardMore b{letter-spacing:.02em; text-transform:none; color: rgba(234,240,255,.82); font-weight:650}
    .hint{
      margin-top: 14px;
      color: rgba(234,240,255,.58);
      font-size: 12px;
      transform: translateZ(16px);
    }

    /* Process spatial steps */
    .process{
      transform-style: preserve-3d;
    }
    .rail{
      position: relative;
      margin-top: 18px;
      border-radius: 28px;
      border: 1px solid rgba(255,255,255,.10);
      background: rgba(255,255,255,.04);
      backdrop-filter: blur(16px);
      -webkit-backdrop-filter: blur(16px);
      box-shadow: var(--shadow2);
      padding: 18px;
      transform: translateZ(34px);
      overflow:hidden;
    }
    .rail:before{
      content:"";
      position:absolute; inset:-1px;
      background:
        radial-gradient(900px 260px at 10% 0%, rgba(138,244,255,.12), transparent 65%),
        radial-gradient(900px 260px at 90% 100%, rgba(182,167,255,.10), transparent 66%);
      opacity:.9;
      pointer-events:none;
    }
    .flow{
      display:grid;
      grid-template-columns: repeat(4, 1fr);
      gap: 12px;
      position:relative;
      transform-style: preserve-3d;
    }
    .step{
      position:relative;
      border-radius: 18px;
      border: 1px solid rgba(255,255,255,.10);
      background: rgba(0,0,0,.22);
      padding: 14px 14px 12px;
      transform-style: preserve-3d;
      overflow:hidden;
      min-height: 150px;
    }
    .step:before{
      content:"";
      position:absolute; inset:-1px;
      background: radial-gradient(420px 200px at var(--mx, 50%) var(--my, 30%), rgba(118,255,184,.12), transparent 62%);
      opacity:.8;
      pointer-events:none;
    }
    .stepNum{
      font-family: var(--mono);
      font-size: 11px;
      letter-spacing: .18em;
      color: rgba(234,240,255,.62);
      text-transform: uppercase;
      transform: translateZ(14px);
    }
    .stepTitle{
      margin: 10px 0 8px;
      font-weight: 720;
      letter-spacing: -.01em;
      transform: translateZ(14px);
    }
    .stepBody{
      margin: 0;
      font-size: 13px;
      line-height: 1.55;
      color: rgba(234,240,255,.70);
      transform: translateZ(12px);
    }
    .beam{
      position:absolute;
      left: 0; right: 0;
      top: 52%;
      height: 2px;
      background: linear-gradient(90deg, rgba(138,244,255,0), rgba(138,244,255,.32), rgba(182,167,255,.28), rgba(138,244,255,0));
      opacity: .6;
      filter: blur(.2px);
      transform: translateZ(10px);
      pointer-events:none;
    }
    .pulse{
      position:absolute;
      top: 50%;
      left: var(--p, 10%);
      width: 18px;
      height: 18px;
      border-radius: 99px;
      background: radial-gradient(circle at 30% 30%, rgba(138,244,255,1), rgba(182,167,255,1));
      box-shadow: 0 0 0 0 rgba(138,244,255,.22);
      transform: translate(-50%,-50%) translateZ(18px);
      animation: pulse 2.2s var(--ease) infinite;
      pointer-events:none;
    }
    @keyframes pulse{
      0%{box-shadow: 0 0 0 0 rgba(138,244,255,.22); opacity:.95}
      70%{box-shadow: 0 0 0 18px rgba(138,244,255,0); opacity:.75}
      100%{box-shadow: 0 0 0 0 rgba(138,244,255,0); opacity:.85}
    }

    /* Work / Proof scene */
    .proof{
      display:grid;
      grid-template-columns: 1fr 1fr;
      gap: 14px;
      align-items: start;
      transform-style: preserve-3d;
      margin-top: 14px;
    }
    .transformer{
      border-radius: 28px;
      border: 1px solid rgba(255,255,255,.10);
      background: linear-gradient(180deg, rgba(255,255,255,.06), rgba(255,255,255,.03));
      backdrop-filter: blur(18px);
      -webkit-backdrop-filter: blur(18px);
      box-shadow: var(--shadow2);
      padding: 18px;
      transform: translateZ(36px) rotateY(-4deg);
      overflow:hidden;
      position:relative;
    }
    .transformer:before{
      content:"";
      position:absolute; inset:-1px;
      background:
        radial-gradient(680px 260px at var(--mx, 40%) var(--my, 20%), rgba(138,244,255,.14), transparent 65%),
        radial-gradient(680px 260px at 90% 90%, rgba(182,167,255,.12), transparent 65%);
      opacity:.9;
      pointer-events:none;
    }
    .tabs{
      display:flex; gap: 8px; flex-wrap: wrap;
      transform: translateZ(18px);
      margin-bottom: 12px;
    }
    .tab{
      padding: 10px 12px;
      border-radius: 999px;
      border: 1px solid rgba(255,255,255,.10);
      background: rgba(0,0,0,.18);
      color: rgba(234,240,255,.82);
      font-size: 12px;
      letter-spacing: .2px;
      cursor:pointer;
      user-select:none;
      transition: transform .22s var(--ease), border-color .22s var(--ease), background .22s var(--ease);
      transform-style: preserve-3d;
      will-change: transform;
    }
    .tab.active{
      background: linear-gradient(180deg, rgba(138,244,255,.16), rgba(182,167,255,.10));
      border-color: rgba(138,244,255,.22);
      color: rgba(234,240,255,.92);
    }
    .tab:hover{transform: translate3d(0,-1px,10px); border-color: rgba(255,255,255,.16); background: rgba(255,255,255,.06)}
    .panel3d{
      display:grid;
      grid-template-columns: 1fr;
      gap: 10px;
      transform-style: preserve-3d;
    }
    .copyBox{
      border-radius: 20px;
      border: 1px solid rgba(255,255,255,.10);
      background: rgba(0,0,0,.22);
      padding: 14px;
      position:relative;
      overflow:hidden;
      transform-style: preserve-3d;
    }
    .copyBox:before{
      content:"";
      position:absolute; inset:-1px;
      background: radial-gradient(520px 220px at var(--mx, 50%) var(--my, 30%), rgba(118,255,184,.10), transparent 62%);
      opacity:.75;
      pointer-events:none;
    }
    .labelRow{
      display:flex;
      align-items:center;
      justify-content: space-between;
      gap: 10px;
      transform: translateZ(14px);
      margin-bottom: 10px;
    }
    .label{
      font-family: var(--mono);
      font-size: 11px;
      letter-spacing: .18em;
      text-transform: uppercase;
      color: rgba(234,240,255,.62);
    }
    .score{
      font-size: 12px;
      color: rgba(234,240,255,.70);
    }
    .score b{color: rgba(234,240,255,.92)}
    .copyText{
      margin: 0;
      font-size: 14px;
      line-height: 1.6;
      color: rgba(234,240,255,.82);
      transform: translateZ(12px);
      text-shadow: 0 10px 22px rgba(0,0,0,.35);
    }
    .morphHint{
      margin-top: 12px;
      display:flex;
      gap: 10px;
      align-items:center;
      justify-content: space-between;
      color: rgba(234,240,255,.60);
      font-size: 12px;
      transform: translateZ(14px);
    }
    .toggle{
      display:flex; gap: 8px; align-items:center;
    }
    .switch{
      width: 46px; height: 28px;
      border-radius: 999px;
      border: 1px solid rgba(255,255,255,.14);
      background: rgba(255,255,255,.06);
      position:relative;
      cursor:pointer;
      transition: background .2s var(--ease), border-color .2s var(--ease);
      box-shadow: 0 18px 40px rgba(0,0,0,.25);
    }
    .knob{
      position:absolute; top: 3px; left: 3px;
      width: 22px; height: 22px; border-radius: 999px;
      background: linear-gradient(180deg, rgba(255,255,255,.22), rgba(255,255,255,.10));
      border: 1px solid rgba(255,255,255,.16);
      box-shadow: 0 12px 28px rgba(0,0,0,.35);
      transition: transform .25s var(--ease);
    }
    .switch.on{
      background: linear-gradient(180deg, rgba(138,244,255,.20), rgba(182,167,255,.12));
      border-color: rgba(138,244,255,.24);
    }
    .switch.on .knob{ transform: translateX(18px); }

    .sideProof{
      border-radius: 28px;
      border: 1px solid rgba(255,255,255,.10);
      background: rgba(0,0,0,.22);
      backdrop-filter: blur(16px);
      -webkit-backdrop-filter: blur(16px);
      box-shadow: var(--shadow2);
      padding: 18px;
      transform: translateZ(34px) rotateY(5deg);
      overflow:hidden;
      position:relative;
    }
    .sideProof:before{
      content:"";
      position:absolute; inset:-1px;
      background: radial-gradient(740px 260px at 15% 10%, rgba(182,167,255,.12), transparent 66%);
      opacity:.9;
      pointer-events:none;
    }
    .sideProof h3{
      margin: 0 0 10px;
      letter-spacing: -.02em;
      font-size: 16px;
      transform: translateZ(16px);
    }
    .bullets{
      margin: 0;
      padding: 0 0 0 16px;
      color: rgba(234,240,255,.72);
      line-height: 1.7;
      font-size: 13.5px;
      transform: translateZ(14px);
    }
    .bullets li{margin: 6px 0}
    .note{
      margin-top: 12px;
      color: rgba(234,240,255,.62);
      font-size: 12px;
      transform: translateZ(12px);
    }

    /* Final CTA scene */
    .final{
      transform-style: preserve-3d;
      text-align: center;
    }
    .big{
      font-size: clamp(30px, 4.2vw, 60px);
      line-height: 1.02;
      letter-spacing: -0.04em;
      margin: 0 0 12px;
      text-shadow: 0 18px 55px rgba(0,0,0,.60);
      transform-style: preserve-3d;
    }
    .big span{display:block}
    .big .a{transform: translateZ(46px)}
    .big .b{transform: translateZ(68px)}
    .big .c{transform: translateZ(50px)}
    .final .sub2{
      margin: 0 auto;
      max-width: 70ch;
      color: rgba(234,240,255,.74);
      line-height: 1.6;
      font-size: 15px;
      transform: translateZ(24px);
    }
    .contactRow{
      margin-top: 18px;
      display:flex;
      justify-content:center;
      gap: 12px;
      flex-wrap: wrap;
      transform-style: preserve-3d;
    }
    .linkBtn{
      min-width: 170px;
      justify-content:center;
    }

    /* --- Progress / scroll hint --- */
    .progress{
      position: fixed;
      left: 14px;
      bottom: 14px;
      z-index: 40;
      pointer-events: none;
      display:flex;
      gap: 10px;
      align-items:center;
      opacity: .9;
      transform: translateZ(0);
    }
    .barWrap{
      width: 128px;
      height: 10px;
      border-radius: 999px;
      border: 1px solid rgba(255,255,255,.12);
      background: rgba(0,0,0,.25);
      backdrop-filter: blur(10px);
      -webkit-backdrop-filter: blur(10px);
      overflow:hidden;
      box-shadow: 0 14px 40px rgba(0,0,0,.35);
    }
    .barFill{
      height: 100%;
      width: 20%;
      border-radius: 999px;
      background: linear-gradient(90deg, rgba(138,244,255,.90), rgba(182,167,255,.85));
      filter: drop-shadow(0 8px 14px rgba(138,244,255,.14));
      transform-origin: left;
      transform: scaleX(var(--p, .1));
    }
    .progress small{
      font-family: var(--mono);
      font-size: 11px;
      letter-spacing: .14em;
      text-transform: uppercase;
      color: rgba(234,240,255,.62);
    }

    /* --- Reveal / cinematic transitions --- */
    .reveal{
      opacity: 0;
      transform: translate3d(0, 14px, 0) translateZ(0);
      filter: blur(6px);
      transition: opacity .8s var(--ease), transform .8s var(--ease), filter .8s var(--ease);
    }
    .reveal.on{
      opacity: 1;
      transform: translate3d(0, 0, 0) translateZ(0);
      filter: blur(0px);
    }

    /* --- Responsive --- */
    @media (max-width: 980px){
      .heroLayout{grid-template-columns: 1fr; gap: 14px}
      .heroObj{height: min(390px, 48vh)}
      .authority{grid-template-columns: 1fr; gap: 12px}
      .about{grid-template-columns: 1fr; gap: 12px}
      .cards{grid-template-columns: repeat(2, 1fr)}
      .flow{grid-template-columns: 1fr 1fr}
      .proof{grid-template-columns: 1fr; gap: 12px}
      .navlinks{gap: 6px}
      .chip{padding: 9px 10px}
      .barWrap{width: 112px}
    }
    @media (max-width: 520px){
      .nav .name span{display:none}
      .chip span.t{display:none}
      .cards{grid-template-columns: 1fr}
      .flow{grid-template-columns: 1fr}
      section.scene{padding-top: 86px}
      .btn{width: 100%}
      .heroActions{gap: 10px}
      .linkBtn{min-width: 100%}
      .progress{left: 10px; bottom: 10px}
    }

    /* Reduced motion */
    @media (prefers-reduced-motion: reduce){
      .grain{animation:none}
      .slab:after{animation:none}
      .pulse{animation:none}
      .reveal{transition:none; opacity:1; transform:none; filter:none}
      .btn,.chip,.cardFace{transition:none}
    }
  </style>
</head>
<body>
  <canvas id="bg" aria-hidden="true"></canvas>
  <div class="film" aria-hidden="true"></div>
  <div class="grain" aria-hidden="true"></div>

  <div class="hud">
    <div class="nav" role="navigation" aria-label="Primary">
      <div class="brand">
        <div class="sig" aria-hidden="true"></div>
        <div class="name">
          <strong>Hanan Arif</strong>
          <span>Conversion-focused Copywriter</span>
        </div>
      </div>
      <div class="navlinks">
        <a class="chip magnet" href="#services" data-go="services"><span class="dot" aria-hidden="true"></span><span class="t">Services</span></a>
        <a class="chip magnet" href="#proof" data-go="proof"><span class="dot" aria-hidden="true"></span><span class="t">Proof</span></a>
        <a class="chip ctaChip magnet" href="#contact" data-go="contact"><span class="dot" aria-hidden="true"></span><span class="t">Start the conversation</span></a>
      </div>
    </div>
  </div>

  <div class="progress" aria-hidden="true">
    <div class="barWrap"><div class="barFill" id="barFill"></div></div>
    <small id="sceneLabel">Scene 01</small>
  </div>

  <div class="stage" id="stage">
    <div class="camera" id="camera">
      <div class="scenes" id="scenes">

        <!-- 1 HERO SCENE -->
        <section class="scene" id="hero" data-scene="01">
          <div class="wrap">
            <div class="grid3d" aria-hidden="true"></div>

            <div class="heroLayout">
              <div class="headline">
                <div class="kicker reveal"><i aria-hidden="true"></i> The portfolio itself is the proof</div>

                <h1 class="h1 reveal" style="transition-delay:.08s">
                  <span class="line">I don’t write <span class="glow">words</span>.</span>
                  <span class="line">I design <span class="glow">decisions</span>.</span>
                  <span class="line">Quietly. Precisely.</span>
                </h1>

                <p class="sub reveal" style="transition-delay:.16s">
                  Copy that moves people — and numbers. The kind that feels inevitable.
                </p>

                <div class="heroActions reveal" style="transition-delay:.22s">
                  <a class="btn btnPrimary magnet" href="#proof" data-go="proof">
                    See What My Words Can Do →
                  </a>
                  <a class="btn btnGhost magnet" href="#services" data-go="services">
                    What I write (and why it converts)
                  </a>
                </div>

                <div class="micro reveal" style="transition-delay:.28s">
                  Calm authority. <b>Premium strategy.</b> No noise.
                </div>
              </div>

              <div class="heroObj" aria-hidden="false">
                <div class="slab parallax reveal" data-depth="0.9" style="transition-delay:.12s">
                  <div class="slabInner">
                    <div>
                      <div class="slabTop">
                        <div class="pill"><span class="bar" aria-hidden="true"></span> Conversion Lens</div>
                        <div class="fine">Designed to sell</div>
                      </div>

                      <div class="metrics">
                        <div class="metric parallax" data-depth="1.2">
                          <strong>Clarity</strong>
                          <span>Remove friction. Keep desire.</span>
                        </div>
                        <div class="metric parallax" data-depth="1.1">
                          <strong>Specificity</strong>
                          <span>Make outcomes measurable.</span>
                        </div>
                        <div class="metric parallax" data-depth="1.05">
                          <strong>Positioning</strong>
                          <span>Be the obvious choice.</span>
                        </div>
                        <div class="metric parallax" data-depth="1.15">
                          <strong>Momentum</strong>
                          <span>Every line earns the next.</span>
                        </div>
                      </div>
                    </div>

                    <div class="slabBottom">
                      <div class="quote">
                        <p>
                          “Good copy sounds nice.<br>
                          <b>Great copy makes the right action feel like relief.</b>”
                        </p>
                      </div>
                      <div class="fine">Scroll to move the camera</div>
                    </div>
                  </div>
                </div>
              </div>

            </div>
          </div>
        </section>

        <!-- 2 AUTHORITY SCENE -->
        <section class="scene" id="authority" data-scene="02">
          <div class="wrap">
            <div class="authority">
              <div class="stack">
                <p class="line reveal">Copy isn’t <strong>art</strong>.</p>
                <p class="line reveal" style="transition-delay:.06s">It’s <strong>psychology</strong>.</p>
                <p class="line reveal" style="transition-delay:.12s">And psychology moves <strong>money</strong>.</p>
                <p class="sceneLead reveal" style="transition-delay:.18s">
                  I write with one goal: remove doubt, focus desire, and guide a clean “yes.”
                  Not louder. Just sharper.
                </p>
              </div>

              <div class="pullQuote reveal parallax" data-depth="1.0" style="transition-delay:.10s">
                <div class="label" style="margin-bottom:10px; transform: translateZ(14px);">What clients pay for</div>
                <div style="display:grid; gap:10px; transform-style: preserve-3d;">
                  <div class="cred parallax" data-depth="1.2">
                    <strong>Message discipline</strong>
                    <span>No wandering. No extra “nice-to-have” paragraphs. Just conversion structure.</span>
                  </div>
                  <div class="cred parallax" data-depth="1.05">
                    <strong>Strategic calm</strong>
                    <span>Premium brands don’t beg. They lead.</span>
                  </div>
                  <div class="cred parallax" data-depth="1.1">
                    <strong>Decision design</strong>
                    <span>Headlines, proof, offers, and CTAs that click into place.</span>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </section>

        <!-- 3 ABOUT SCENE -->
        <section class="scene" id="about" data-scene="03">
          <div class="wrap">
            <div class="about">
              <div>
                <h2 class="sceneTitle reveal">
                  <span class="z1">I’m Hanan.</span>
                  <span class="z2">I build</span>
                  <span class="z3">high-intent journeys.</span>
                </h2>
                <p class="sceneLead reveal" style="transition-delay:.08s">
                  My work is where brand voice meets revenue reality.
                </p>

                <div class="story reveal parallax" data-depth="1.05" style="margin-top:14px; transition-delay:.12s">
                  <p>
                    I don’t chase clever.
                    I chase the moment a reader thinks: <b>“That’s me.”</b>
                  </p>
                  <p>
                    Then I turn that recognition into motion — with structure, rhythm, and proof.
                  </p>
                  <p>
                    If your offer is strong, my job is to make the <b>decision</b> feel simple.
                  </p>
                </div>
              </div>

              <div class="credGrid">
                <div class="cred reveal parallax" data-depth="1.2" style="transition-delay:.10s">
                  <strong>Positioning first</strong>
                  <span>Before writing: what are we really selling, to whom, and why now?</span>
                </div>
                <div class="cred reveal parallax" data-depth="1.1" style="transition-delay:.14s">
                  <strong>Proof without shouting</strong>
                  <span>Authority can be quiet. The copy should still land.</span>
                </div>
                <div class="cred reveal parallax" data-depth="1.0" style="transition-delay:.18s">
                  <strong>Lines that earn their keep</strong>
                  <span>Every sentence either reduces risk, increases desire, or moves the reader forward.</span>
                </div>
                <div class="cred reveal parallax" data-depth="1.15" style="transition-delay:.22s">
                  <strong>Premium tone control</strong>
                  <span>Confident, modern, and intentional — never salesy, never vague.</span>
                </div>
              </div>
            </div>
          </div>
        </section>

        <!-- 4 SERVICES SCENE -->
        <section class="scene" id="services" data-scene="04">
          <div class="wrap services">
            <h2 class="sceneTitle reveal">
              <span class="z1">Services</span>
              <span class="z2">with</span>
              <span class="z3">real weight.</span>
            </h2>
            <p class="sceneLead reveal" style="transition-delay:.08s">
              Built like systems, not “pages.” Hover for the deeper promise.
            </p>

            <div class="cards">
              <div class="card3d magnet reveal" tabindex="0" role="button" aria-label="Website Copy" data-detail="You get a site that reads like clarity: what you do, who it's for, why you win — and the next step that feels natural." style="transition-delay:.06s">
                <div class="cardFace">
                  <h3 class="cardTitle">Website Copy</h3>
                  <p class="cardDesc">Positioning-led pages that make your value obvious in seconds.</p>
                  <div class="cardMore"><span>Hover</span><b>to go deeper</b></div>
                </div>
              </div>

              <div class="card3d magnet reveal" tabindex="0" role="button" aria-label="Landing Pages" data-detail="One page. One decision. Attention captured, objections handled, action triggered — without sounding like a template." style="transition-delay:.10s">
                <div class="cardFace">
                  <h3 class="cardTitle">Landing Pages</h3>
                  <p class="cardDesc">High-focus narratives engineered for clicks, sign-ups, and sales.</p>
                  <div class="cardMore"><span>Hover</span><b>to go deeper</b></div>
                </div>
              </div>

              <div class="card3d magnet reveal" tabindex="0" role="button" aria-label="Sales Pages" data-detail="Long-form that doesn’t ramble. The right sequence: desire → proof → inevitability → yes." style="transition-delay:.14s">
                <div class="cardFace">
                  <h3 class="cardTitle">Sales Pages</h3>
                  <p class="cardDesc">Structured persuasion: story, proof, offer clarity, and clean urgency.</p>
                  <div class="cardMore"><span>Hover</span><b>to go deeper</b></div>
                </div>
              </div>

              <div class="card3d magnet reveal" tabindex="0" role="button" aria-label="Email Sequences" data-detail="Emails that feel like a conversation — but behave like a machine. Trust built. Desire stacked. Action repeated." style="transition-delay:.18s">
                <div class="cardFace">
                  <h3 class="cardTitle">Email Sequences</h3>
                  <p class="cardDesc">Retention + revenue: welcome, nurture, launch, and win-back sequences.</p>
                  <div class="cardMore"><span>Hover</span><b>to go deeper</b></div>
                </div>
              </div>

              <div class="card3d magnet reveal" tabindex="0" role="button" aria-label="Brand Messaging" data-detail="Voice, pillars, promises, and proof — the messaging architecture everything else builds on." style="transition-delay:.22s">
                <div class="cardFace">
                  <h3 class="cardTitle">Brand Messaging</h3>
                  <p class="cardDesc">The language system that keeps your marketing consistent and premium.</p>
                  <div class="cardMore"><span>Hover</span><b>to go deeper</b></div>
                </div>
              </div>
            </div>

            <div class="hint reveal" style="transition-delay:.26s">
              Tip: move your cursor near a card — it reacts like it has mass.
            </div>
          </div>
        </section>

        <!-- 5 PROCESS SCENE -->
        <section class="scene" id="process" data-scene="05">
          <div class="wrap process">
            <h2 class="sceneTitle reveal">
              <span class="z1">My process</span>
              <span class="z2">is a</span>
              <span class="z3">decision system.</span>
            </h2>
            <p class="sceneLead reveal" style="transition-delay:.08s">
              Not “write, revise, ship.” This is how we turn your offer into momentum.
            </p>

            <div class="rail reveal parallax" data-depth="1.0" style="transition-delay:.12s">
              <div class="beam" aria-hidden="true"></div>
              <div class="pulse" aria-hidden="true" style="--p: 12%"></div>
              <div class="pulse" aria-hidden="true" style="--p: 38%; animation-delay:.35s"></div>
              <div class="pulse" aria-hidden="true" style="--p: 64%; animation-delay:.7s"></div>
              <div class="pulse" aria-hidden="true" style="--p: 88%; animation-delay:1.05s"></div>

              <div class="flow">
                <div class="step magnet">
                  <div class="stepNum">Step 01</div>
                  <div class="stepTitle">Diagnose</div>
                  <p class="stepBody">We find the leak: clarity, offer, proof, or friction.</p>
                </div>
                <div class="step magnet">
                  <div class="stepNum">Step 02</div>
                  <div class="stepTitle">Position</div>
                  <p class="stepBody">We define the “obvious choice” angle and the objections to pre-solve.</p>
                </div>
                <div class="step magnet">
                  <div class="stepNum">Step 03</div>
                  <div class="stepTitle">Build</div>
                  <p class="stepBody">I write the sequence: attention → belief → desire → action.</p>
                </div>
                <div class="step magnet">
                  <div class="stepNum">Step 04</div>
                  <div class="stepTitle">Refine</div>
                  <p class="stepBody">Tighten, sharpen, remove noise. Keep the inevitability.</p>
                </div>
              </div>
            </div>
          </div>
        </section>

        <!-- 6 WORK / PROOF SCENE -->
        <section class="scene" id="proof" data-scene="06">
          <div class="wrap">
            <h2 class="sceneTitle reveal">
              <span class="z1">Proof</span>
              <span class="z2">you can</span>
              <span class="z3">feel.</span>
            </h2>
            <p class="sceneLead reveal" style="transition-delay:.08s">
              Tap the switches. Watch the copy tighten into a decision.
            </p>

            <div class="proof">
              <div class="transformer reveal parallax" data-depth="1.0" style="transition-delay:.12s">
                <div class="tabs" role="tablist" aria-label="Proof examples">
                  <div class="tab active magnet" role="tab" aria-selected="true" tabindex="0" data-case="saas">SaaS Landing</div>
                  <div class="tab magnet" role="tab" aria-selected="false" tabindex="0" data-case="coach">Coach Offer</div>
                  <div class="tab magnet" role="tab" aria-selected="false" tabindex="0" data-case="ecom">Ecom Email</div>
                </div>

                <div class="panel3d">
                  <div class="copyBox parallax" data-depth="1.1">
                    <div class="labelRow">
                      <div class="label">Before</div>
                      <div class="score">Signal: <b id="beforeSignal">low</b> • Friction: <b id="beforeFriction">high</b></div>
                    </div>
                    <p class="copyText" id="beforeText">
                      Our platform offers innovative solutions to help teams streamline workflow and improve productivity across projects.
                    </p>
                  </div>

                  <div class="copyBox parallax" data-depth="1.2">
                    <div class="labelRow">
                      <div class="label">After</div>
                      <div class="score">Signal: <b id="afterSignal">high</b> • Friction: <b id="afterFriction">low</b></div>
                    </div>
                    <p class="copyText" id="afterText">
                      Stop losing hours to “status updates.” One dashboard that shows what’s blocked, what’s moving, and what to ship next — without chasing people.
                    </p>
                  </div>

                  <div class="morphHint">
                    <div class="toggle">
                      <div class="label">Cinematic morph</div>
                      <div class="switch magnet on" id="morphSwitch" role="switch" aria-checked="true" tabindex="0">
                        <div class="knob" aria-hidden="true"></div>
                      </div>
                    </div>
                    <div class="label">Hover near the text to bend the light</div>
                  </div>
                </div>
              </div>

              <div class="sideProof reveal parallax" data-depth="0.95" style="transition-delay:.18s">
                <h3>What changes when the copy is right</h3>
                <ul class="bullets">
                  <li>The offer becomes <b>easy to repeat</b> — word-for-word.</li>
                  <li>Objections get handled <b>before</b> they appear.</li>
                  <li>The CTA feels like the next step — not a leap.</li>
                  <li>You attract buyers, not browsers.</li>
                </ul>
                <div class="note">
                  The goal isn’t persuasion.<br>
                  It’s <b>alignment</b> — until “yes” feels obvious.
                </div>

                <div class="heroActions" style="margin-top: 14px;">
                  <a class="btn btnPrimary magnet" href="#contact" data-go="contact">Let’s talk outcomes</a>
                  <a class="btn btnGhost magnet" href="mailto:hananhereat@gmail.com">Email me</a>
                </div>
              </div>
            </div>
          </div>
        </section>

        <!-- 7 CTA SCENE -->
        <section class="scene" id="contact" data-scene="07">
          <div class="wrap final">
            <div class="grid3d" aria-hidden="true" style="opacity:.25; transform: translateZ(-280px) rotateX(6deg);"></div>

            <h2 class="big reveal">
              <span class="a">If your copy isn’t converting,</span>
              <span class="b">it’s quietly draining</span>
              <span class="c">your revenue.</span>
            </h2>

            <p class="sub2 reveal" style="transition-delay:.10s">
              Want the calm version of growth? The one built on clarity, proof, and a clean path to “yes.”
            </p>

            <div class="contactRow reveal" style="transition-delay:.18s">
              <a class="btn btnPrimary magnet linkBtn" href="mailto:hananhereat@gmail.com">
                Email — Start the conversation
              </a>
              <a class="btn btnGhost magnet linkBtn" href="https://www.instagram.com/_hanann786/" target="_blank" rel="noopener noreferrer">
                Instagram — Say hi
              </a>
              <a class="btn btnGhost magnet linkBtn" href="https://www.linkedin.com/in/hanan-arif-03b526396" target="_blank" rel="noopener noreferrer">
                LinkedIn — Connect
              </a>
            </div>

            <div class="micro reveal" style="transition-delay:.24s">
              <b>hananhereat@gmail.com</b> • Remote • Available for premium projects
            </div>
          </div>
        </section>

      </div>
    </div>
  </div>

  <!-- Three.js -->
  <script src="https://unpkg.com/three@0.160.0/build/three.min.js"></script>

  <script>
    (() => {
      const clamp = (v, a, b) => Math.max(a, Math.min(b, v));
      const lerp = (a,b,t) => a + (b-a)*t;
      const prefersReduced = matchMedia('(prefers-reduced-motion: reduce)').matches;

      // ---------------------------
      // Cinematic inertial "camera scroll"
      // ---------------------------
      const scenesEl = document.getElementById('scenes');
      const cameraEl = document.getElementById('camera');
      const stageEl = document.getElementById('stage');
      const barFill = document.getElementById('barFill');
      const sceneLabel = document.getElementById('sceneLabel');

      const sections = Array.from(document.querySelectorAll('section.scene'));
      const totalScenes = sections.length;

      let targetY = 0;
      let currentY = 0;
      let vel = 0;
      let lastWheelT = performance.now();

      // virtual scroll range
      let maxY = 0;
      function recalc() {
        const h = window.innerHeight;
        maxY = h * (totalScenes - 1);
        targetY = clamp(targetY, 0, maxY);
        currentY = clamp(currentY, 0, maxY);
      }
      window.addEventListener('resize', recalc, {passive:true});
      recalc();

      function goTo(id) {
        const idx = sections.findIndex(s => s.id === id);
        if (idx >= 0) targetY = idx * window.innerHeight;
      }

      // Wheel + touch handling
      window.addEventListener('wheel', (e) => {
        if (prefersReduced) return;
        const now = performance.now();
        const dt = Math.max(1, now - lastWheelT);
        lastWheelT = now;

        const delta = e.deltaY;
        // Non-linear scaling to keep precise but cinematic
        const boost = clamp(Math.abs(delta) / 80, 0.8, 2.8);
        targetY = clamp(targetY + delta * 0.95 * boost, 0, maxY);

        // slight "dolly blur" impulse
        const impulse = clamp(Math.abs(delta) / 1400, 0, 0.26);
        vel += (delta > 0 ? 1 : -1) * impulse * (dt < 16 ? 1.25 : 1);
      }, {passive:true});

      // Touch drag
      let touchActive = false, tStartY = 0, tStartTarget = 0, lastTouchY = 0, touchVel = 0;
      window.addEventListener('touchstart', (e) => {
        if (e.touches.length !== 1) return;
        touchActive = true;
        tStartY = e.touches[0].clientY;
        lastTouchY = tStartY;
        tStartTarget = targetY;
      }, {passive:true});
      window.addEventListener('touchmove', (e) => {
        if (!touchActive || e.touches.length !== 1) return;
        const y = e.touches[0].clientY;
        const dy = (tStartY - y);
        targetY = clamp(tStartTarget + dy * 1.15, 0, maxY);
        touchVel = (lastTouchY - y) * 0.002;
        lastTouchY = y;
      }, {passive:true});
      window.addEventListener('touchend', () => { touchActive = false; vel += clamp(touchVel, -0.22, 0.22); }, {passive:true});

      // Keyboard
      window.addEventListener('keydown', (e) => {
        if (e.key === 'ArrowDown' || e.key === 'PageDown') targetY = clamp(targetY + innerHeight * 0.85, 0, maxY);
        if (e.key === 'ArrowUp' || e.key === 'PageUp') targetY = clamp(targetY - innerHeight * 0.85, 0, maxY);
        if (e.key === 'Home') targetY = 0;
        if (e.key === 'End') targetY = maxY;
      });

      // Nav go-to
      document.querySelectorAll('[data-go]').forEach(a => {
        a.addEventListener('click', (e) => {
          e.preventDefault();
          goTo(a.getAttribute('data-go'));
        });
      });

      // ---------------------------
      // Cursor force field + parallax + magnet
      // ---------------------------
      const pointer = { x: innerWidth * 0.5, y: innerHeight * 0.5, nx:0, ny:0, vx:0, vy:0 };
      const smoothPointer = { x: pointer.x, y: pointer.y, nx:0, ny:0 };
      function setPointer(x,y){
        pointer.x = x; pointer.y = y;
        pointer.nx = (x / innerWidth) * 2 - 1;
        pointer.ny = -((y / innerHeight) * 2 - 1);
      }
      window.addEventListener('mousemove', (e) => {
        pointer.vx = e.movementX || 0;
        pointer.vy = e.movementY || 0;
        setPointer(e.clientX, e.clientY);
      }, {passive:true});
      window.addEventListener('touchmove', (e) => {
        if (!e.touches[0]) return;
        const t = e.touches[0];
        setPointer(t.clientX, t.clientY);
      }, {passive:true});

      const magnets = Array.from(document.querySelectorAll('.magnet'));
      const parallaxEls = Array.from(document.querySelectorAll('.parallax'));
      const lightTracked = Array.from(document.querySelectorAll('.btn,.chip,.cardFace,.quote,.cred,.step,.copyBox,.transformer,.sideProof,.pullQuote,.story,.slab'));

      function applyLocalLight(el, eX, eY){
        const r = el.getBoundingClientRect();
        const mx = clamp(((eX - r.left) / r.width) * 100, 0, 100);
        const my = clamp(((eY - r.top) / r.height) * 100, 0, 100);
        el.style.setProperty('--mx', mx + '%');
        el.style.setProperty('--my', my + '%');
      }
      window.addEventListener('mousemove', (e) => {
        for (const el of lightTracked) applyLocalLight(el, e.clientX, e.clientY);
      }, {passive:true});

      // Service card hover: reveal deeper copy
      document.querySelectorAll('.card3d').forEach(card => {
        const face = card.querySelector('.cardFace');
        const baseTitle = face.querySelector('.cardTitle').textContent;
        const baseDesc = face.querySelector('.cardDesc').textContent;
        const detail = card.getAttribute('data-detail') || baseDesc;

        let showing = false;
        const showDetail = () => {
          if (showing) return;
          showing = true;
          face.querySelector('.cardDesc').textContent = detail;
          face.querySelector('.cardMore').innerHTML = "<span>Depth</span><b>revealed</b>";
        };
        const hideDetail = () => {
          if (!showing) return;
          showing = false;
          face.querySelector('.cardTitle').textContent = baseTitle;
          face.querySelector('.cardDesc').textContent = baseDesc;
          face.querySelector('.cardMore').innerHTML = "<span>Hover</span><b>to go deeper</b>";
        };

        card.addEventListener('mouseenter', showDetail);
        card.addEventListener('mouseleave', hideDetail);
        card.addEventListener('focus', showDetail);
        card.addEventListener('blur', hideDetail);

        // keyboard activate toggles
        card.addEventListener('keydown', (e) => {
          if (e.key === 'Enter' || e.key === ' ') {
            e.preventDefault();
            showing ? hideDetail() : showDetail();
          }
        });
      });

      // ---------------------------
      // Proof transformer: cases + cinematic morph
      // ---------------------------
      const cases = {
        saas: {
          before: "Our platform offers innovative solutions to help teams streamline workflow and improve productivity across projects.",
          after: "Stop losing hours to “status updates.” One dashboard that shows what’s blocked, what’s moving, and what to ship next — without chasing people.",
          metaB: {signal:"low", friction:"high"},
          metaA: {signal:"high", friction:"low"},
        },
        coach: {
          before: "I help people unlock their potential and achieve their goals through coaching programs designed for personal growth and success.",
          after: "You don’t need more motivation. You need a plan you’ll actually follow. Weekly coaching that turns overwhelm into a schedule — and a schedule into results.",
          metaB: {signal:"medium", friction:"high"},
          metaA: {signal:"high", friction:"low"},
        },
        ecom: {
          before: "Shop our latest collection today. Quality products, great prices, and fast shipping. Don’t miss out!",
          after: "Your skin doesn’t need 10 steps. It needs the right ones. This 3-piece set cuts the noise — cleanse, repair, protect — and feels like a fresh start tonight.",
          metaB: {signal:"low", friction:"medium"},
          metaA: {signal:"high", friction:"low"},
        }
      };

      const tabs = Array.from(document.querySelectorAll('.tab'));
      const beforeTextEl = document.getElementById('beforeText');
      const afterTextEl = document.getElementById('afterText');
      const beforeSignal = document.getElementById('beforeSignal');
      const beforeFriction = document.getElementById('beforeFriction');
      const afterSignal = document.getElementById('afterSignal');
      const afterFriction = document.getElementById('afterFriction');

      const morphSwitch = document.getElementById('morphSwitch');
      let morphOn = true;

      function setCase(key){
        const c = cases[key];
        if (!c) return;

        tabs.forEach(t => {
          const is = t.dataset.case === key;
          t.classList.toggle('active', is);
          t.setAttribute('aria-selected', is ? 'true' : 'false');
        });

        if (!morphOn || prefersReduced){
          beforeTextEl.textContent = c.before;
          afterTextEl.textContent = c.after;
        } else {
          morphText(beforeTextEl, c.before, 320);
          morphText(afterTextEl, c.after, 380);
        }

        beforeSignal.textContent = c.metaB.signal;
        beforeFriction.textContent = c.metaB.friction;
        afterSignal.textContent = c.metaA.signal;
        afterFriction.textContent = c.metaA.friction;
      }

      function morphText(el, target, duration=360){
        const start = el.textContent || "";
        const maxLen = Math.max(start.length, target.length);
        const startTime = performance.now();

        function frame(t){
          const p = clamp((t - startTime) / duration, 0, 1);
          const eased = 1 - Math.pow(1 - p, 3);
          const reveal = Math.floor(lerp(0, maxLen, eased));

          // "film dissolve" effect: keep a few random chars in the tail
          let out = "";
          for (let i=0;i<maxLen;i++){
            const s = start[i] ?? "";
            const tt = target[i] ?? "";
            if (i < reveal){
              out += tt;
            } else {
              const pick = Math.random() < 0.55 ? s : (Math.random() < 0.12 ? "•" : "");
              out += pick;
            }
          }
          out = out.replace(/\s{2,}/g,' ');
          el.textContent = out.trimEnd();

          if (p < 1) requestAnimationFrame(frame);
          else el.textContent = target;
        }
        requestAnimationFrame(frame);
      }

      tabs.forEach(tab => {
        tab.addEventListener('click', () => setCase(tab.dataset.case));
        tab.addEventListener('keydown', (e) => {
          if (e.key === 'Enter' || e.key === ' ') { e.preventDefault(); setCase(tab.dataset.case); }
        });
      });

      function setMorph(on){
        morphOn = !!on;
        morphSwitch.classList.toggle('on', morphOn);
        morphSwitch.setAttribute('aria-checked', morphOn ? 'true' : 'false');
      }
      morphSwitch.addEventListener('click', () => setMorph(!morphOn));
      morphSwitch.addEventListener('keydown', (e) => {
        if (e.key === 'Enter' || e.key === ' ') { e.preventDefault(); setMorph(!morphOn); }
      });

      setCase('saas');

      // ---------------------------
      // Reveal system per scene + copy progressive
      // ---------------------------
      const revealEls = Array.from(document.querySelectorAll('.reveal'));
      function updateReveals(){
        const h = innerHeight;
        // scene index based on currentY
        const s = clamp(currentY / h, 0, totalScenes - 1);
        const sceneIdx = Math.round(s);
        const sceneNum = String(sceneIdx + 1).padStart(2, '0');
        sceneLabel.textContent = `Scene ${sceneNum}`;

        // progress bar
        const prog = maxY === 0 ? 0 : currentY / maxY;
        barFill.style.setProperty('--p', String(clamp(prog, 0, 1)));

        // reveal elements that are near current view by offsetTop
        const viewTop = currentY;
        const viewBottom = currentY + h;

        for (const el of revealEls){
          const sec = el.closest('section.scene');
          if (!sec) continue;
          const idx = sections.indexOf(sec);
          const top = idx * h;
          const isNear = (top < viewBottom + h*0.25) && (top > viewTop - h*1.0);
          el.classList.toggle('on', isNear);
        }
      }

      // ---------------------------
      // Three.js: fluid-like ripple plane + soft particles
      // ---------------------------
      const canvas = document.getElementById('bg');
      const renderer = new THREE.WebGLRenderer({canvas, antialias: true, alpha: true, powerPreference: 'high-performance'});
      renderer.setPixelRatio(Math.min(devicePixelRatio, 2));
      renderer.setSize(innerWidth, innerHeight, false);

      const scene = new THREE.Scene();
      const camera = new THREE.PerspectiveCamera(48, innerWidth/innerHeight, 0.1, 100);
      camera.position.set(0, 0, 4.2);

      // Lighting (cursor-reactive)
      const key = new THREE.DirectionalLight(0x8af4ff, 0.55);
      key.position.set(-1.5, 1.2, 2.0);
      scene.add(key);

      const fill = new THREE.DirectionalLight(0xb6a7ff, 0.45);
      fill.position.set(1.6, -0.6, 1.2);
      scene.add(fill);

      const rim = new THREE.PointLight(0x76ffb8, 0.55, 18, 2);
      rim.position.set(0.6, 0.7, 2.8);
      scene.add(rim);

      // Background: plane with vertex displacement and ripple impulses
      const geo = new THREE.PlaneGeometry(8.5, 6.0, 140, 100);
      const uniforms = {
        uTime: {value: 0},
        uPointer: {value: new THREE.Vector2(0,0)},
        uScroll: {value: 0},
        uVel: {value: 0},
        uAspect: {value: innerWidth/innerHeight},
        uColorA: {value: new THREE.Color(0x8af4ff)},
        uColorB: {value: new THREE.Color(0xb6a7ff)},
        uColorC: {value: new THREE.Color(0x76ffb8)},
        uRipples: {value: Array.from({length: 10}, () => new THREE.Vector4(999,999,0,0))} // x,y,amp,t
      };

      const mat = new THREE.ShaderMaterial({
        transparent: true,
        depthWrite: false,
        uniforms,
        vertexShader: `
          uniform float uTime;
          uniform vec2 uPointer;
          uniform float uScroll;
          uniform float uVel;
          uniform vec4 uRipples[10];

          varying vec2 vUv;
          varying float vW;
          varying vec3 vPos;

          float hash(vec2 p){ return fract(sin(dot(p, vec2(127.1,311.7))) * 43758.5453123); }
          float noise(vec2 p){
            vec2 i = floor(p);
            vec2 f = fract(p);
            float a = hash(i);
            float b = hash(i + vec2(1.0,0.0));
            float c = hash(i + vec2(0.0,1.0));
            float d = hash(i + vec2(1.0,1.0));
            vec2 u = f*f*(3.0-2.0*f);
            return mix(a, b, u.x) + (c - a)*u.y*(1.0-u.x) + (d - b)*u.x*u.y;
          }

          void main(){
            vUv = uv;
            vec3 pos = position;

            // base animated flow
            float t = uTime * 0.22;
            float n1 = noise((uv*3.2) + vec2(t, -t*0.9));
            float n2 = noise((uv*6.2) + vec2(-t*0.6, t*1.1));
            float flow = (n1*0.65 + n2*0.35);

            // pointer influence (force field)
            float d = distance(uv, (uPointer * 0.5 + 0.5));
            float pwr = smoothstep(0.55, 0.0, d);
            float swirl = sin((uv.x + uv.y + t*2.0) * 8.0) * 0.04;

            // ripples impulses
            float rip = 0.0;
            for (int i=0;i<10;i++){
              vec4 r = uRipples[i];
              vec2 rp = r.xy;
              float amp = r.z;
              float age = r.w;
              float dd = distance(uv, rp);
              float wave = sin(32.0 * dd - age * 9.0) * exp(-dd*8.0) * exp(-age*1.6);
              rip += wave * amp;
            }

            float scrollWave = sin((uv.y*3.4) + uScroll*0.002) * 0.06;
            float vWave = (flow - 0.5) * 0.22 + pwr * (0.22 + abs(uVel)*0.25) + swirl + rip * 0.28 + scrollWave;

            pos.z += vWave;

            vW = vWave;
            vPos = pos;

            gl_Position = projectionMatrix * modelViewMatrix * vec4(pos, 1.0);
          }
        `,
        fragmentShader: `
          uniform float uTime;
          uniform float uScroll;
          uniform vec3 uColorA;
          uniform vec3 uColorB;
          uniform vec3 uColorC;

          varying vec2 vUv;
          varying float vW;
          varying vec3 vPos;

          float vignette(vec2 uv){
            vec2 p = uv - 0.5;
            float d = dot(p,p);
            return smoothstep(0.62, 0.18, d);
          }

          void main(){
            float t = uTime * 0.12;

            // soft gradient blend with flow and scroll
            float g = (vUv.y*0.65 + 0.18) + sin(t + vUv.x*2.0)*0.06;
            vec3 col = mix(uColorA, uColorB, smoothstep(0.0, 1.0, g));
            col = mix(col, uColorC, smoothstep(0.18, 0.95, vUv.x) * 0.20);

            // "liquid light" highlights
            float h = smoothstep(0.02, 0.22, abs(vW));
            col += (uColorA * 0.10 + uColorB * 0.08) * h;

            // depth fog & cinematic dark
            float fog = smoothstep(0.0, 1.0, (vPos.z + 0.45));
            col = mix(col, col * 0.55, fog);

            float vig = vignette(vUv);
            float alpha = 0.42 * vig;

            // subtle moving haze
            alpha += 0.06 * sin((vUv.x + vUv.y + t) * 3.0);
            alpha = clamp(alpha, 0.05, 0.52);

            gl_FragColor = vec4(col, alpha);
          }
        `
      });

      const plane = new THREE.Mesh(geo, mat);
      plane.position.set(0, 0, 0);
      scene.add(plane);

      // Particles: soft bokeh points
      const pCount = 260;
      const pGeo = new THREE.BufferGeometry();
      const pos = new Float32Array(pCount * 3);
      const size = new Float32Array(pCount);
      for (let i=0;i<pCount;i++){
        const ix = i*3;
        pos[ix+0] = (Math.random()*2-1) * 5.2;
        pos[ix+1] = (Math.random()*2-1) * 3.4;
        pos[ix+2] = -1.2 - Math.random()*2.6;
        size[i] = 2.5 + Math.random()*7.0;
      }
      pGeo.setAttribute('position', new THREE.BufferAttribute(pos, 3));
      pGeo.setAttribute('aSize', new THREE.BufferAttribute(size, 1));

      const pMat = new THREE.ShaderMaterial({
        transparent: true,
        depthWrite: false,
        blending: THREE.AdditiveBlending,
        uniforms: {
          uTime: {value: 0},
          uPointer: {value: new THREE.Vector2(0,0)},
          uScroll: {value: 0},
          uA: {value: new THREE.Color(0x8af4ff)},
          uB: {value: new THREE.Color(0xb6a7ff)}
        },
        vertexShader: `
          uniform float uTime;
          uniform vec2 uPointer;
          uniform float uScroll;
          attribute float aSize;
          varying float vS;
          varying float vF;

          void main(){
            vec3 p = position;

            float t = uTime * 0.18;
            float sway = sin((p.x*0.6 + p.y*0.4) + t) * 0.06;
            float sway2 = cos((p.y*0.7 - p.x*0.3) + t*1.3) * 0.05;

            // scroll drift
            p.y += sin(p.x*0.2 + uScroll*0.0008) * 0.06;
            p.x += sway;
            p.y += sway2;

            // pointer attraction (very soft)
            vec2 pp = vec2(p.x/5.2, p.y/3.4);
            float d = distance(pp, uPointer);
            float f = smoothstep(0.8, 0.0, d) * 0.22;
            p.x += (uPointer.x - pp.x) * f * 0.18;
            p.y += (uPointer.y - pp.y) * f * 0.18;

            vS = aSize;
            vF = f;

            vec4 mv = modelViewMatrix * vec4(p, 1.0);
            gl_Position = projectionMatrix * mv;

            float perspective = (1.0 / -mv.z);
            gl_PointSize = aSize * 1.6 * perspective;
          }
        `,
        fragmentShader: `
          uniform float uTime;
          uniform vec3 uA;
          uniform vec3 uB;
          varying float vS;
          varying float vF;

          void main(){
            vec2 uv = gl_PointCoord - 0.5;
            float d = dot(uv,uv);
            float soft = smoothstep(0.22, 0.02, d);

            vec3 col = mix(uB, uA, 0.5 + 0.5*sin(uTime*0.25 + vS*0.2));
            col *= 0.7 + vF * 0.9;

            float a = soft * 0.22;
            gl_FragColor = vec4(col, a);
          }
        `
      });

      const points = new THREE.Points(pGeo, pMat);
      scene.add(points);

      function resizeGL(){
        renderer.setPixelRatio(Math.min(devicePixelRatio, 2));
        renderer.setSize(innerWidth, innerHeight, false);
        camera.aspect = innerWidth/innerHeight;
        camera.updateProjectionMatrix();
        uniforms.uAspect.value = innerWidth/innerHeight;
      }
      window.addEventListener('resize', resizeGL, {passive:true});

      // Ripple injection (cursor fluid)
      let rippleIdx = 0;
      let lastRippleT = 0;
      function injectRipple(u, v, amp){
        const arr = uniforms.uRipples.value;
        arr[rippleIdx].set(u, v, amp, 0.0);
        rippleIdx = (rippleIdx + 1) % arr.length;
      }

      // ---------------------------
      // Main loop
      // ---------------------------
      let t0 = performance.now();
      let blur = 0;

      function tick(now){
        const dt = clamp((now - t0) / 1000, 0.0, 0.05);
        t0 = now;

        // Pointer smoothing
        smoothPointer.x = lerp(smoothPointer.x, pointer.x, prefersReduced ? 1 : 0.14);
        smoothPointer.y = lerp(smoothPointer.y, pointer.y, prefersReduced ? 1 : 0.14);
        smoothPointer.nx = (smoothPointer.x / innerWidth) * 2 - 1;
        smoothPointer.ny = -((smoothPointer.y / innerHeight) * 2 - 1);

        // Inertial camera: spring to target
        const tension = prefersReduced ? 1.0 : 0.12;
        const friction = prefersReduced ? 1.0 : 0.78;

        const force = (targetY - currentY) * tension;
        vel = (vel + force * dt * 60) * friction;
        currentY = clamp(currentY + vel * (dt * 60) * 10, 0, maxY);

        // Scenes translate (camera dolly)
        scenesEl.style.transform = `translate3d(0, ${-currentY}px, 0)`;

        // cinematic micro camera tilt + blur based on velocity
        const vAbs = Math.abs(vel);
        const tiltX = clamp((smoothPointer.ny) * 2.2, -2.2, 2.2);
        const tiltY = clamp((smoothPointer.nx) * 2.4, -2.4, 2.4);
        const z = 0;
        const roll = clamp(smoothPointer.nx * 1.2, -1.2, 1.2);

        blur = lerp(blur, clamp(vAbs * 0.16, 0, 8), prefersReduced ? 1 : 0.12);
        cameraEl.style.filter = `saturate(1.02) contrast(1.02) blur(${blur.toFixed(2)}px)`;

        cameraEl.style.transform = `translate3d(0,0,0) rotateX(${tiltX}deg) rotateY(${tiltY}deg) rotateZ(${roll}deg)`;

        // Parallax planes inside scenes
        for (const el of parallaxEls){
          const depth = parseFloat(el.dataset.depth || '1');
          // subtle z + pointer parallax
          const px = smoothPointer.nx * 10 * depth;
          const py = smoothPointer.ny * 7 * depth;
          el.style.transform = `translate3d(${px.toFixed(2)}px, ${py.toFixed(2)}px, 0) translateZ(${(12*depth).toFixed(2)}px)`;
        }

        // Magnetic elements (force field)
        for (const el of magnets){
          const r = el.getBoundingClientRect();
          const cx = r.left + r.width/2;
          const cy = r.top + r.height/2;
          const dx = smoothPointer.x - cx;
          const dy = smoothPointer.y - cy;
          const dist = Math.hypot(dx,dy);
          const range = Math.max(90, Math.min(160, r.width*0.9));
          const m = clamp(1 - dist / range, 0, 1);
          const tx = dx * m * 0.12;
          const ty = dy * m * 0.12;
          const lift = m * 18;

          // tilt
          const rotY = clamp(dx / Math.max(1,r.width) * 10, -10, 10) * m;
          const rotX = clamp(-dy / Math.max(1,r.height) * 10, -10, 10) * m;

          el.style.transform = `translate3d(${tx.toFixed(2)}px, ${ty.toFixed(2)}px, ${lift.toFixed(2)}px) rotateX(${rotX.toFixed(2)}deg) rotateY(${rotY.toFixed(2)}deg)`;
        }

        // Update reveals + labels
        updateReveals();

        // WebGL uniforms
        uniforms.uTime.value += dt;
        uniforms.uPointer.value.set(smoothPointer.nx, smoothPointer.ny);
        uniforms.uScroll.value = currentY;
        uniforms.uVel.value = vel;

        pMat.uniforms.uTime.value = uniforms.uTime.value;
        pMat.uniforms.uPointer.value.set(smoothPointer.nx*0.55, smoothPointer.ny*0.55);
        pMat.uniforms.uScroll.value = currentY;

        // cursor ripple injection
        const speed = Math.hypot(pointer.vx, pointer.vy);
        if (!prefersReduced){
          const interval = speed > 6 ? 38 : 70;
          if (now - lastRippleT > interval){
            lastRippleT = now;
            const u = clamp((smoothPointer.x / innerWidth), 0, 1);
            const v = clamp((smoothPointer.y / innerHeight), 0, 1);
            const amp = clamp(speed / 120, 0.04, 0.22);
            injectRipple(u, 1.0 - v, amp);
          }
        }

        // Age ripples
        const rArr = uniforms.uRipples.value;
        for (let i=0;i<rArr.length;i++){
          const rw = rArr[i].w;
          if (rw < 4.0) rArr[i].w = rw + dt * 1.0;
        }

        // Cursor-reactive lighting
        key.position.x = lerp(key.position.x, -1.2 + smoothPointer.nx * 0.8, prefersReduced ? 1 : 0.08);
        key.position.y = lerp(key.position.y,  1.0 + smoothPointer.ny * 0.6, prefersReduced ? 1 : 0.08);
        fill.position.x = lerp(fill.position.x,  1.4 + smoothPointer.nx * 0.7, prefersReduced ? 1 : 0.08);
        fill.position.y = lerp(fill.position.y, -0.8 + smoothPointer.ny * 0.5, prefersReduced ? 1 : 0.08);
        rim.position.x  = lerp(rim.position.x,  0.2 + smoothPointer.nx * 1.1, prefersReduced ? 1 : 0.10);
        rim.position.y  = lerp(rim.position.y,  0.4 + smoothPointer.ny * 0.9, prefersReduced ? 1 : 0.10);

        renderer.render(scene, camera);
        requestAnimationFrame(tick);
      }

      // initial pointer
      setPointer(innerWidth*0.52, innerHeight*0.46);
      updateReveals();
      resizeGL();
      requestAnimationFrame(tick);

      // Ensure transforms don't persist on leave (esp. mobile)
      window.addEventListener('mouseleave', () => {
        setPointer(innerWidth*0.5, innerHeight*0.5);
      });

      // Prevent default anchor jumps; we drive the camera
      document.querySelectorAll('a[href^="#"]').forEach(a => {
        a.addEventListener('click', (e) => {
          const href = a.getAttribute('href');
          if (!href || href.length < 2) return;
          const id = href.slice(1);
          if (document.getElementById(id)) {
            e.preventDefault();
            goTo(id);
          }
        });
      });
    })();
  </script>
</body>
</html>
