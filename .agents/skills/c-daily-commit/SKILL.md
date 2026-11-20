---
name: c-daily-commit
description: Finish and commit one verified daily C tutorial TODO with its checklist tick and evidence. Use /skill:c-daily-commit with a Daily TODO ID when asked to finish or commit today's learning work.
disable-model-invocation: true
---

# C Daily Commit

Run only on explicit invocation. It authorizes one local commit, not a push. Work from the repository root.

1. Take one `NN.NN` TODO ID from the invocation. If missing, show the next unchecked ID and ask which one to commit. Read [ROADMAP.md](../../../ROADMAP.md) and locate the exact ID in the numbered phase READMEs. Resolve its project folder from that section. Stop if missing, duplicated, or already checked.
2. Run `git status --short`, `git diff`, and `git diff --cached`; inspect new files too. Stop if anything is already staged and ask the user to clear or commit it. Select only today's relevant result files in the project folder. Do not stage binaries, credentials, unrelated work, or an empty result.
3. Run the selected TODO's verification or confirm recorded evidence for manual, device, or emulator checks with the user. Use the actual command and outcome. If verification fails or evidence is missing, report what is blocked and leave the box unchecked. Do not implement missing work as part of committing.
4. Change only the selected `[ ]` to `[x]`. Stage exact reviewed paths, not `git add .`. If that README or a result file contains unrelated edits, stage only relevant hunks, or stop and ask if they cannot be isolated safely. Run `git diff --cached --check` and inspect `git diff --cached`: the new check and evidence-bearing work must both be present, with no unrelated changes.
5. Commit with a specific Conventional Commit subject and a body containing `Verify: <command or manual check and result>`, then a blank line and `Daily-Todo: <ID>`. Example:

   ```text
   feat(cat): copy one file to stdout

   Verify: built with clang; cmp matched expected output

   Daily-Todo: 49.01
   ```

6. Confirm the new commit with `git show --stat HEAD` and verify its ID and tick. Report the short hash and next unchecked TODO. If the commit fails and no commit was created, undo only the staging performed by this skill and revert only its checkbox edit; keep the implementation, evidence, and other edits for retry. Never bypass commit hooks or rewrite history.
