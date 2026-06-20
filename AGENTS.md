# AGENTS.md

Instructions for AI agents working in this repository.

## Agent skills

### Issue tracker

Issues and PRDs are tracked in GitHub Issues (`pugofer/pug`) via the `gh` CLI; external PRs are **not** a triage surface. See `docs/agents/issue-tracker.md`.

### Triage labels

Canonical labels — `needs-triage`, `needs-info`, `ready-for-agent`, `ready-for-human`, `wontfix` (`wontfix` already exists in the repo). See `docs/agents/triage-labels.md`.

### Domain docs

Single-context: one `CONTEXT.md` + `docs/adr/` at the repo root (created lazily). See `docs/agents/domain.md`.
